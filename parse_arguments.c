#include "ft_ls.h"

static int	determine_flag_type(char *param, int flags)
{
	int i;

	i = 1;
	while (param[i])
	{
		if (param[i] == 'l')
			flags = (flags | FLAG_L);
		else if (param[i] == 'R')
			flags = (flags | FLAG_BR);
		else if (param[i] == 'r')
			flags = (flags | FLAG_SR);
		else if (param[i] == 'a')
			flags = (flags | FLAG_A);
		else if (param[i] == 't')
			flags = (flags | FLAG_T);
		i++;
	}
	return (flags);
}

char		*parse_arguments(int argc, char **argv, int *flags)
{
	int		i;
	char	*filename;

	*flags = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		*flags = determine_flag_type(argv[i], *flags);
		i++;
	}
	filename = (i == argc ? "." : argv[i]);
	return (filename);
}