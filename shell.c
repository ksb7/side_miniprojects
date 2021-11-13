#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define line_delim "\n\0, ;"
char** tokens(char* input)
{
	char** tokens = malloc(64 * sizeof(char*)); //2d array to hold the address and the content of each word
	char* token; //to store the content of each word
	int position = 0;
	if(!tokens)
	{
		fprintf(stderr, "allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, line_delim); 
       	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		//according to man page
		//In each subsequent call that should parse the  same  string,  str (token)  must  be  NULL.

		token = strtok(NULL, line_delim);
	}
	tokens[position] = NULL; //finish the job
	int i;
	for(i = 0; i < position; i++)
		printf("tokens %s\n", tokens[i]);
	return tokens;
}
char* input(void)
{
	char *input = malloc(1* sizeof(char));
	int i = 0; //to hold the position
	int j = 1; //to hold the total space allocated
	/*check for input 
	 * and whether the character is new line*/
	while (scanf("%c", &input[i]) == 1 && input[i] != '\n') 
	/*scanf returns the number of elements scanned
	 * therefore it equals 1*/
	{
		input = realloc(input, j*sizeof(char)); //realloc the total space used plus 1 more
		i++;
		j++;
	}
	return input;
}
int main()
{
	char* inputbleh = input();
	char** lines = tokens(inputbleh);
	free(lines);
	free(inputbleh); //free the allocated memory for tokens
	return 0;
}
