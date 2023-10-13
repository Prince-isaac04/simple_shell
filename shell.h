#ifndef SHELL_H_
#define SHELL_H_

int main(void);
void scan_instruction(char *instruct, size_t size);
void enforce_instruction();
void output_prompt(void);
void token_instruction(char *tokener);

#endif
