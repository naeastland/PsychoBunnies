/*
Programmer: Nate Eastland
Class: Cpts 121, Fall 2014; Lab Section 7
Programming Assignment: PA4
Date: 10/7/14
Description: This program simulates a version of the dice game of 'Craps'.
*/

#include "craps.h"

/*******************************************************
  Function: print_game_rules()                    
  Date Created: 10/7/14                                             
  Date Last Modified: 10/7/14                                      
  Description: Prints out the rules for the game and redisplays the options menu,
				allowing the player to select from the menu again.
  Input parameters: None                                   
  Returns: Nothing                                         
********************************************************/

void print_game_rules()
{
	int option = 0;

	printf("\nWelcome to the game! The rules for 'Craps' are as follows.\n");
	printf("\nThe player (you) will roll two (imaginary) dice. Once the dice come to rest (figuratively), the values on their faces will be added together.\n");
	printf("\nIf they add up to 7 or 11 on your first throw, you win! However, if they add up to 2, 3 or 12 on the first throw, you lose.\n");
	printf("\nIf you get any of the other numbers on your first throw (4, 5, 6, 8, 9, or 10), that number beomces your 'point'. In order to win, you must reroll your 'point'.\n");
	printf("If you roll a 7 before you make your 'point', you lose. And thems is the rules.\n");
	printf("\nYou must make your first bet on the Pass Line, but all other bets after that are optional (bet amount can be 0).\n");

	do
	{
		display_menu();
		option = get_option();
		input_validation(option);
	} while(option < 1 || option > 3);
	
	check_options(option);
}

/*******************************************************
  Function: display_menu()                   
  Date Created: 10/7/14                                             
  Date Last Modified: 10/7/14                                       
  Description: A display menu giving the player interface options.                                  
  Input parameters: None                                    
  Returns: Nothing                                           
********************************************************/

void display_menu()
{
	printf(" \n");
	printf("1. Play Game\n");
	printf("2. Rules\n");
	printf("3. Exit\n");
}

/*******************************************************
  Function: check_options()                   
  Date Created: 10/7/14                                             
  Date Last Modified: 10/7/14                                       
  Description: Sends the menu option selected by the player to a switch.                                   
  Input parameters: The menu option selected by the player.                                  
  Returns: Nothing                                        
********************************************************/

void check_options(int option)
{
	switch (option)
	{ 
		case PLAY: play_game();
			break;
		case RULES: print_game_rules();
			break;
		case EXIT: printf("Bye Bye!\n");
			break;
	}
}

/*******************************************************
  Function: display_options()                    
  Date Created: 10/7/14                                             
  Date Last Modified: 10/8/14                                       
  Description: Displays an options menu, reads the user input,
				and checks the input for validity.                                  
  Input parameters: None                                  
  Returns: Nothing                                         
********************************************************/

void display_options()
{
	int option = 0;

	//input validation loop
	do
	{	
		display_menu();
		option = get_option();
		input_validation(option);
	} while(option < 1 || option > 3);
	
	check_options(option);
}

/*******************************************************
  Function: play_game()                   
  Date Created: 10/7/14                                             
  Date Last Modified: 10/8/14                                      
  Description: This beast runs the game. Within the loop are two conditions which 
				determine gameplay based on whether you are on your first roll or not.
  Input parameters: None                                   
  Returns: Nothing                                         
********************************************************/

void play_game()
{
	//gameplay variables
	int die1 = 0, die2 = 0, sum = 0, win_lose = 1, point = 0, num_rolls = 0, play_again = 1;
	double initial_balance = 0.0, balance = 0.0, wager = 0.0, stake = 0.0, winnings = 0.0;
	
	system("cls");

	balance = get_bank_balance();
	initial_balance = balance;
	chatter_messages(num_rolls, win_lose, die1, die2, initial_balance, balance);

	//loop within which the game play is executed
	while(win_lose != 0)
	{
		//condition that executes only on the first roll
		if (num_rolls == 0)
			{
				system("cls");

				printf("Comin' out! Make your bet on the pass line.\n");

				//takes the player's initial wager, sets the current stake (total on table for current game), deducts wager from balance.
				wager = get_wager_amount(balance);
				stake = wager;
				balance = balance - wager;

				printf("%.2lf down. Hot roll comin'!\n", wager); 

				die1 = roll_die();
				die2 = roll_die();
				chatter_messages(num_rolls, win_lose, die1, die2, initial_balance, balance);

				sum = calculate_sum_dice(die1, die2);
				win_lose = is_win_loss_or_point(sum);

				//condition that sets the player's "point" which is used for the rest of gameplay.
				//the follwoing else if and else are for cases of winning or losing on the first roll.
				if (win_lose == -1)
				{
					point = sum;
					dice_roll(die1, die2);

					printf("Looks like your point is %d.\n", point);
					chatter_messages(num_rolls, win_lose, die1, die2, initial_balance, balance);

					num_rolls++;
				}
				else if(win_lose == 1)
				{
					balance = balance + (1.5 * wager);
					dice_roll(die1, die2);

					printf("Congratulations, you rolled a %d. You win!! Your ending balance is: %.2lf\n", sum, balance + wager);

					win_lose = exit_game(balance);

					stake = 0.0;
					num_rolls = 0;
					point = 0;
				}
				else
				{
					dice_roll(die1, die2);
					printf("Sorry, you lose. Your ending balance is: %.2lf\n", balance);

					win_lose = exit_game(balance);
					chatter_messages(num_rolls, win_lose, die1, die2, initial_balance, balance);

					stake = 0.0;
					num_rolls = 0;
					point = 0;
				}
			}

		//condition statement for controlling gameplay beyond the first roll
		if (num_rolls > 0)
		{
			status(point, balance, stake);

			wager = get_wager_amount(balance);

			die1 = roll_die();
			die2 = roll_die();

			sum = calculate_sum_dice(die1, die2);
			win_lose = is_point_loss_or_neither(sum, point);

			//deducts wager from balance if roll results in neither a winning or losing condition, adds to stake, increments roll counter
			if (win_lose == -1)
			{
				balance = balance - wager;

				system("cls");
	
				dice_roll(die1, die2);
				chatter_messages(num_rolls, win_lose, die1, die2, initial_balance, balance);
			
				stake = stake + wager;
				num_rolls++;
			}
			//manipulates payout, clears stake, asks if player would like to play again.
			else if(win_lose == 1)
			{
				balance = balance + (1.5 * stake);

				system("cls");

				dice_roll(die1, die2);

				printf("Congratulations, you win!! Your ending balance is: %.2lf\n", balance);

				win_lose = exit_game(balance);

				stake = 0.0;
				num_rolls = 0;
				point = 0;
			}
			//deducts wager from balance, clears stake, asks if player would like to play again.
			else 
			{
				balance = balance - wager;
			
				system("cls");

				dice_roll(die1, die2);

				printf("Sorry, you lose. Your ending balance is: %.2lf\n", balance);

				win_lose = exit_game(balance);
				
				stake = 0.0;
				num_rolls = 0;
				point = 0;
			}
		}
	}
}

/*******************************************************
  Function: input_validation()                    
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: This function returns error jests to the user upon 
				entering invalid menu options.
  Input parameters: The menu option entered by the user.                                   
  Returns: Nothing, just talks smack.                                         
********************************************************/  

void input_validation(int option)
{
	int num = rand() % 4 +1;

	if (option < 1 || option > 3)
	{
		if (num == 4)
		{
			printf("Yeeeah.....nope.\n");
		}
		else if (num == 3)
		{
			printf("There were three numbers.....you had one job....\n");
		}
		else if (num == 2)
		{
			printf("Really?\n");
		}
		else
		{
			printf("Hmmm....let's try that again.\n");
		}
	}

}

/*******************************************************
  Function: status()                  
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: This function provides a status bar with current balance,
				amount at stake for the current game, and the players point.
  Input parameters: Current point value, balance, and stake.                              
  Returns: Nothing                                          
********************************************************/

void status(int point, double balance, double stake)
{
	printf("\n************************************************************************\n");
	printf("Current balance: %.2lf\n", balance);
	printf("Total at stake: %.2lf\n", stake);
	printf("Your point: %d\n", point);
	printf("************************************************************************\n");
}

/*******************************************************
  Function: dice_roll()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Provides a text illustration of dice for the rolls
				as well as prints the value of the rolled dice.
  Input parameters: The randomly rolled values for die1 and die2                                   
  Returns: Nothing                                         
********************************************************/

void dice_roll(int die1, int die2)
{
	printf("   _______            \n");
	printf("  /\\ o o o\\         \n");
	printf(" /o \\ o o o\\_______ \n");
	printf("<    >------>    o/ | \n"); 
	printf(" \\ o/  o   /_____/ o| \n");
	printf("  \\/______/      |oo| \n");
	printf("         |   o   |o/  \n");
	printf("         |_______|/   \n");

	printf("%d and %d\n", die1, die2);
}

/*******************************************************
  Function: exit_game()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: This is a function call for an end game message.                              
  Input parameters: None.                                   
  Returns: Nothing.                                          
********************************************************/

int exit_game(double balance)
{
	char yes_no = '\0';
	int num = 0;

	if (balance != 0)
	{
		printf("Would you like to keep playin? (y/n)\n");
		scanf(" %c", &yes_no);
	}
	
	if (yes_no == 'n' || yes_no == 'N')
	{
		num = 0;

		printf("Bye bye!\n");
	}

	if (yes_no == 'y' || yes_no == 'Y');
	{
		num = 1;
	}

	return num;
}

/*******************************************************
  Function: get_option()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Scans for the menu option selected by the player.                                  
  Input parameters: None                                   
  Returns: The number value of the option selected.                                         
********************************************************/

int get_option()
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

/*******************************************************
  Function: get_bank_balance()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Asks the user to input a starting account balance.                                   
  Input parameters: None.                                    
  Returns: The entered account balance.                                         
********************************************************/

double get_bank_balance()
{
	double balance = 0.0;

	printf("Let's get started. \nPlease enter a starting bank balance from which you will place your bets: \n");
	scanf("%lf", &balance);

	return balance;
}

/*******************************************************
  Function: get_wager_amount()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                     
  Description: Asks the player to make a wager, then verifies whether
				or not it is a valid wager. Asks again if input is invalid
  Input parameters: Current account balance.                                   
  Returns: The value of the wager entered.                                         
********************************************************/

double get_wager_amount(double balance)
{
	double wager = 0.0;
	int num = 0;

	printf("How much do you want to bet on this roll?\n");
	scanf("%lf", &wager);

	num = check_wager_amount(wager, balance);

	while (num == 0)
	{
		printf("Sorry, you don't have that much to bet. Please enter a valid wager amount.\n");
		scanf("%lf", &wager);

		num = check_wager_amount(wager, balance);
	}

	return wager;
}

/*******************************************************
  Function: check_wager_amount()                    
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Checks the player's current wager against the current value of
				their account balance.
  Input parameters: The wager amount and the current account balance                                    
  Returns: An int, either a 1 or 0, to indicate if the wager does or does not 
			exceed the available account balance.
********************************************************/

int check_wager_amount(double wager, double balance)
{
	if (wager <= balance)
		return 1;
	else
		return 0;
}

/*******************************************************
  Function: roll_die()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Rolls a die using a randomly generated number from 1 to 6.                                  
  Input parameters: None                                   
  Returns: Result of the random roll.                                         
********************************************************/

int roll_die()
{
	int die_result = rand() % 6 + 1;
	
	return die_result;
}

/*******************************************************
  Function: calculate_sum_dice()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Calculates the sum of the two dice rolled.                                   
  Input parameters: The value of die1 and die2.                                   
  Returns: The sum of the two dice........                                         
********************************************************/

int calculate_sum_dice(int die1_value, int die2_value)
{
	return die1_value + die2_value;
}

/*******************************************************
  Function: is_win_loss_or_point()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Determines if the player wins or losses on the first roll
				or if they roll one of the 'point' numbers.
  Input parameters: The sum of the dice from the first roll                                   
  Returns: An interger value indicating the result. 1 = win, 0 = lose, -1 = point.                                         
********************************************************/

int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if( sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*******************************************************
  Function: is_point_loss_or_neither()                   
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: Determines if the current dice roll, passed in as the sum,
				matches the point value, the losing condition, or anything else.
  Input parameters: The sum of the current dice roll and the players 'point'.                                 
  Returns: An int value of 1 for win, 0 for loss, or -1 for continuation of play.                                         
********************************************************/

int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if ( sum_dice == 7)
	{
		return 0;
	}
	else 
	{
		return -1;
	}
}

/*******************************************************
  Function: adjust_bank_balance()                    
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: This function adjusts the bank balance...for some reason,
				even though it can just as easily done without this function...................
  Input parameters: The current bank balance, amount wagered and an interger to 
					determine what operation is performed (add or subtract).
  Returns: The new bank balance as a double.                                          
********************************************************/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
		bank_balance = bank_balance + wager_amount;
	else if (add_or_subtract == 0)
		bank_balance = bank_balance - wager_amount;
	
	return bank_balance;
}

/*******************************************************
  Function: chatter_messages()                  
  Date Created: 10/7/14                                            
  Date Last Modified: 10/7/14                                      
  Description: This function prints out some chatter during the game depening
				upon the input values given to it.
  Input parameters: How many rolls have been made, a value indicating if the player
					won or lost on their first roll, the player's initial bank balance, 
					and their current bank balance.
  Returns: Nothing.                                        
********************************************************/

void chatter_messages(int number_rolls, int win_loss_neither,int die1, int die2, double initial_bank_balance, double current_bank_balance)
{
	int num = rand() % 3, count = 0;

	if (number_rolls == 0)
	{
		count = number_rolls;
	}

	if((initial_bank_balance >= 10000) && (number_rolls == 0))
	{
		printf("Whoa! Big spender here.\n");
	}

	if((current_bank_balance <= (.25 * initial_bank_balance)) && num == 2)
	{
		printf("You might want to consider taking a break buddy. Gettin low there.\n");
	}

	if ((number_rolls > 4) && (win_loss_neither == 0))
	{
		printf("Bad luck, you had a good run going there.\n");
	}

	if ((die1 == 1 ) && (die2 == 3))
	{
		printf("Little Joe from Kokomo.\n");
	}
}
