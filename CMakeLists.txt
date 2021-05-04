cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe main.cpp includes/computer_random.h
                                    includes/computer_binary.h
                                    includes/game.h
                                    includes/human.h
                                    includes/bTree.h
                                    includes/player.h
                                    includes/playground.h)