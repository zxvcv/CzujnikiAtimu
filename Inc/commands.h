#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>
#include <stdio.h>
#include "data_commands.h"

extern struct Communication_Data ComData;
extern TIM_HandleTypeDef htim6;

/*
funkcja komendy stop

@param com_prop struktura zawieraj¹ca parametry na ktorych beda wywolywane funkcje w tej funkcji
@return (true) gdy wywolanie sie powiodlo (false) w przeciwnym wypadku
*/
bool stop(CommandProperties* CmdPrt);

/*
funkcja komendy measure

@param com_prop struktura zawieraj¹ca parametry na ktorych beda wywolywane funkcje w tej funkcji
@return (true) gdy wywolanie sie powiodlo (false) w przeciwnym wypadku
*/
bool measure(CommandProperties* CmdPrt);

/*
funkcja komendy settings

@param com_prop struktura zawieraj¹ca parametry na ktorych beda wywolywane funkcje w tej funkcji
@return (true) gdy wywolanie sie powiodlo (false) w przeciwnym wypadku
*/
bool settings(CommandProperties* CmdPrt);


#endif //COMMANDS_H
