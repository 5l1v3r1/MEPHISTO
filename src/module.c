#include "module.h"


void* mephisto_module_get_cmd_param_ptr(
    struct mephisto_module_cmd* cmd,
    unsigned int                position
)
{
    return (void *) (cmd->buffer + position)
}

struct mephisto_module_cmd* mephisto_module_create_cmd(
    unsigned int   cmd,
    unsigned int   buffer_size,
    unsigned char* buffer
)
{
    int i = 0;
    struct mephisto_module_cmd* command = kmalloc(
        sizeof(struct mephisto_module_cmd) + buffer_size,
        GFP_KERNEL
    );
    command->cmd         = cmd;
    command->buffer_size = buffer_size;
    command->buffer      = (unsigned char*) &(command[1]);
    for(i = 0; i < buffer_size; i++)
    {
        command->buffer[i] = buffer[i];
    }
    return command;
}

void mephisto_module_delete_cmd(
    struct mephisto_module_cmd* cmd
)
{
    kfree(cmd);
}
