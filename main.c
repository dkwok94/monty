#include "monty.h"
/**
 *main - entry point for interpretor
 *@ac: the number of command line arguments
 *@av: the array of command line argument strings
 *
 *Return: 0 always
 */
int main(int ac, char **av)
{
	int fd, i = 0, j = 0, k = 0;
	unsigned int line_number = 0;
	char *value, *opcode, *buffer;
	ssize_t chars_read;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

//	while (fgetc(fd) != EOF)
//		letters++;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = malloc(sizeof(char) * 10);
	value = malloc(sizeof(char) * 12);

	chars_read = read(fd, buffer, 1024);
	if (chars_read == -1)
	{
		printf("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
		{
			opcode[j] = buffer[i];
			j++;
		}
		else
		{
			opcode[++j] = '\0';
			printf("Opcode: %s\n", opcode);
			while (buffer[i] == ' ')
				i++;
			while (buffer[i] != '\n')
			{
				value[k] = buffer[i];
				i++;
				k++;
				printf("Iteration %d\n", k);
			}
			if (buffer[i + 1] != '\0')
				value[++k] = '\0';
			printf("Value: %s\n", value);
			line_number++;
			opcodecompare(line_number, opcode);
			j = 0;
			k = 0;
		}
		i++;
	}
	printf("Buffer: %s", buffer);
	return (0);
}
