#ifndef __INPUT_FILE_H__
#define __INPUT_FILE_H__
double input_init(input_parameter *param, int id);
int input_stop(int id);
int input_run(int id);
void *worker_thread(void *arg);
#endif
