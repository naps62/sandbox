#include <stdio.h>
#include <starpu.h>

void func(void* buffers[], void *args) {
  printf("%d\n", starpu_combined_worker_get_size());
}

struct starpu_codelet cl = {
  .where = STARPU_CPU,
  .cpu_funcs = { func, NULL },
  .nbuffers = 0,
  .type = STARPU_FORKJOIN,
  .max_parallelism = 10
};

void call() {
  struct starpu_task *t = starpu_task_create();
  t->cl = &cl;

  int param = 1;
  t->cl_arg = &param;
  t->cl_arg_size = sizeof(int);

  t->synchronous = 1;

  starpu_task_submit(t);
}

int main() {
  starpu_init(NULL);

  call();
  call();
  call();

  starpu_shutdown();
}
