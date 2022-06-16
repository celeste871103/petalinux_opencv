#ifndef __OUTPUT_HTTP_H__
#define __OUTPUT_HTTP_H__
int output_init(output_parameter *param, int id);
int output_stop(int id);
int output_run(int id);
int output_cmd(int plugin, unsigned int control_id, unsigned int group, int value);
#endif
