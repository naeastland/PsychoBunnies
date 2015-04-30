/*
Programmer: Nate Eastland
Class: Cpts 121, Fall 2014; Lab Section 7
Programming Assignment: PA4
Date: 10/7/14
Description: This program simulates a version of the dice game of 'Craps'.
*/


#ifndef PA4_H
#define PA4_H
#define RULES 2
#define PLAY 1
#define EXIT 3

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_game_rules();
void display_menu();
void check_options(int option);
void display_options();
void play_game();
void status(int point, double balance, double stake);
void dice_roll(int die1, int die2);
int exit_game(double balance);
void input_validation(int option);
void chatter_messages(int number_rolls, int win_loss_neither, int die1, int die2,
					  double initial_bank_balanc, double current_bank_balance);
int get_option();
int check_wager_amount(double wager, double balance);
int roll_die();
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double get_bank_balance();
double get_wager_amount(double balance);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);


#endif
