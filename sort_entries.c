#include "ft_ls.h"

void	swap_entries(t_file *e1, t_file *e2)
{
	char	*tmp_name;
	t_file	*tmp_subfolder;
	int		tmp_type;
	t_user 	u_id;
	t_group g_id;
	char	*time_str;
	t_size	tmp_size;
	t_information tmp_info;

	tmp_subfolder = e1->subfolder;
	tmp_info = e1->info;
	e1->subfolder = e2->subfolder;
	e1->info = e2->info;
	e2->subfolder = tmp_subfolder;
	e2->info = tmp_info;
}

void	sort_entries_default(t_file *entries, int flags)
{
	t_file *entry;
	t_file *comparison;
	int res;

	entry = entries;
	while (entry && entry->next)
	{
		comparison = entry->next;
		while (comparison)
		{
			if ((res = ft_strcmp(entry->info.name, comparison->info.name)) > 0 &&
			!(flags & FLAG_SR))
				swap_entries(entry, comparison);
			else if (ft_strcmp(entry->info.name, comparison->info.name) < 0 &&
			(flags & FLAG_SR))
				swap_entries(entry, comparison);
			comparison = comparison->next;
		}
		if (entry->subfolder)
			sort_entries_default(entry->subfolder, flags);
		entry = entry->next;
	}
}