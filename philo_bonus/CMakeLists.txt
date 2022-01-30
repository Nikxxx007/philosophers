cmake_minimum_required(VERSION 3.20)
project(philo_bonus C)


set(CMAKE_C_STANDARD 99)

add_executable(philo    src/main.c includes/philo.h
                        src/parser/parser.c
                        src/exit/er_exit.c
                        src/init/init.c
                        src/utils/ft_atoi.c
                        src/utils/ft_strncmp.c
                        src/utils/cur_time.c src/cleaner/cleaner.c src/begin/begin.c src/live_circle/start_life.c src/utils/print_mes.c)
