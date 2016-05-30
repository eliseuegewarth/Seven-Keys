# ```Class SevenKeys : public Game```
Class that represents the entire game and manages the main screens.
##Public:
###``` SevenKeys()```
This is the class constructor method. He starts the game in "headset" and plays a song.
####```AudioManagerMusic * music2```
Instance of the audio manager that is responsible for playing the game music.
## Private:

###```INITIAL_SANITY_OF_THE_PLAYER```
Is the initial value of sanity (HP) of the player.
###```INITIAL_NUMBER_OF_LIVES_OF_THE_PLAYER```
Is the initial value of the player's lives.
###```int number_of_players_lives```
Is the number of the player's lives.
###```double player_sanity```
Is the player's sanity points.
###```Level * load_level(const string& screen_type)```
Returns the pointer to a screen that will be loaded.
####Parameters
#####```const string& screen_type```
String that contains the type of screen that will be loaded.
####Variables
#####```Environment *env```
It is an object of the class environment. Is a pointer to the current instance of the game environment.
#####```shared_ptr <Font> font```
---comment---
#####```double width```
Width of screen in pixels.
#####```double height```
Height of screen in pixels.
#####```string ant```
String that contains the old type of screen.
#####```char novo[256]```
---comment---
#####```string num_id```
---comment---
#####```char num_id2[10]```
---comment---
#####```int novo_id```
---comment---
#####```char path[256]```
---comment---
#####```char music_path[256]```
---comment---
#####```Level *lvl```
The screen to be loaded.
#####```Level * level_to_be_loaded```
Returns the screen that will be loaded.

