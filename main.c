#include "ft_ls.h"

t_file	*save_file_information(struct dirent *current, char *filepath)
{
	t_file *new;
	struct stat st_stat;
	char *complete_filepath;
	time_t time;

	new = (t_file *)malloc(sizeof(t_file));
	new->info.name = ft_strdup(current->d_name);
	new->info.type = current->d_type;
	complete_filepath = ft_strjoin(ft_strjoin(filepath, "/"), new->info.name);
	stat(complete_filepath, &st_stat);
	new->info.mode = st_stat.st_mode;
	time = st_stat.st_mtimespec.tv_sec;
	new->info.blocks = st_stat.st_blocks;
	new->info.hlinks.nbr = ft_itoa(st_stat.st_nlink);
	new->info.hlinks.len = ft_strlen(new->info.hlinks.nbr);
	new->info.time_str = ft_strsub(ctime(&time), 4, 12);
	new->info.size.nbr = ft_itoa(st_stat.st_size);
	new->info.size.len = ft_strlen(new->info.size.nbr);
	new->info.user.name = ft_strdup(getpwuid(st_stat.st_uid)->pw_name);
	new->info.user.len = ft_strlen(new->info.user.name);
	new->info.group.name = getgrgid(st_stat.st_gid)->gr_name;
	new->info.group.len = ft_strlen(new->info.group.name);
	new->subfolder = NULL;
	new->next = NULL;
	return (new);
}

void	print_permissions(mode_t mode, int type)
{
	int i;
	const char chars[] = "rwxrwxrwx";
	char buf[10];
	char typechar;

	if (type == 4)
		typechar = 'd';
	else
		typechar = '-';
	i = 0;
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
		i++;
	}
  buf[9] = '\0';
  ft_printf("%c%s", typechar, buf);
}

static char		get_file_acl(char *path)
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

void	print_entries_default(t_file *entries, int flags, char *filepath)
{
	t_file *entry;
	char 	*current_filepath;
	size_t buflen = 0;
	char	*buf;

	ft_printf("Total %d\n", entries->info.blocks);
	entry = entries;
	while (entry)
	{
		if (entry->info.name[0] != '.' || (flags & FLAG_A))
		{
			print_permissions(entry->info.mode, entry->info.type);
			ft_printf("%c ", get_file_acl(ft_strjoin(ft_strjoin(filepath, "/"), entry->info.name)));
			ft_printf("%*s %-*s %-*s %*s %s %s\n", entries->info.hlinks.len, entry->info.hlinks.nbr, entries->info.user.len, entry->info.user.name, entries->info.group.len, entry->info.group.name, entries->info.size.len, entry->info.size.nbr, entry->info.time_str, entry->info.name, entry->info.blocks);
		}
		entry = entry->next;
	}
	if (flags & FLAG_BR)
	{
		entry = entries;
		while (entry)
		{
			if (entry->subfolder && (entry->info.name[0] != '.' || (flags & FLAG_A)))
			{
				current_filepath = ft_strjoin(filepath, "/");
				ft_printf("\n%s%s:\n", current_filepath, entry->info.name);
				print_entries_default(entry->subfolder, flags, ft_strjoin(current_filepath, entry->info.name));
			}
			entry = entry->next;
		}
	}
}

t_file	*get_files(char *filename)
{
	struct dirent	*current;
	int				entry_nbr;
	t_file			*entries;
	t_file			*head;
	DIR				*directory;

	directory = opendir(filename);
	if (directory == NULL)
		return (NULL);
	head = save_file_information(readdir(directory), filename);
	if (head->info.type == 4 && !ft_strequ(head->info.name, "..") \
	&& !ft_strequ(head->info.name, "."))
	head->subfolder = get_files(ft_strjoin(ft_strjoin(filename, "/"), head->info.name));
	entries = head;
	while ((current = readdir(directory)))
	{
		entries->next = save_file_information(current, filename);
		entries = entries->next;
		head->info.blocks = head->info.blocks + entries->info.blocks;
		if (head->info.user.len < entries->info.user.len)
			head->info.user.len = entries->info.user.len;
		if (head->info.group.len < entries->info.group.len)
			head->info.group.len = entries->info.group.len;
		if (head->info.size.len < entries->info.size.len)
			head->info.size.len = entries->info.size.len;
		if (head->info.hlinks.len < entries->info.hlinks.len)
			head->info.hlinks.len = entries->info.hlinks.len;
		if (entries->info.type == 4 && !ft_strequ(entries->info.name, "..") \
		&& !ft_strequ(entries->info.name, "."))
			entries->subfolder = get_files(ft_strjoin(ft_strjoin(filename, "/"), entries->info.name));
	}
	closedir(directory);
	head->info.user.len++;
	head->info.group.len++;
	return (head);
}

int		main(int argc, char **argv)
{
	DIR				*directory;
	struct dirent	*current;
	char			*filename;
	t_file			*entries;
	int				flags;

	filename = parse_arguments(argc, argv, &flags);
	entries = get_files(filename);
	sort_entries_default(entries, flags);
	print_entries_default(entries, flags, ".");
}