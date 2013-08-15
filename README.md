liars-dice
==========

This idea comes from the unfinished project 'Loose-Cannons', the idea is to make the dice game 'liar's dice' in C++
(Liar's Dice Wiki)[http://en.wikipedia.org/wiki/Liar's_dice] (Dudo Wiki)[http://en.wikipedia.org/wiki/Dudo]
Each player starts having five dice and a cup, which is used for shaking the dice and concealing your dice from the other players. Players roll die in order, to determine where and in what order they sit. Highest first, then next lowest and so on. In the event of a tie between 2 players, they simply re-roll until one gains a higher score. After deciding who starts the game (this can be done by making each player roll one die, for example), the players shake their dice in their cups, and then each player looks at his or her own dice, but keeps these dice concealed from the other players. Then, the first player says how many dice are showing - at a minimum - a certain number (for example, "five threes", meaning there are at least 5 dice showing a three, which can be fact or fictional) and tells the next player (play always moves clockwise) to raise, call or spot on the announcement.
Raise: If the player wants to increase, he or she increases the number of dice (e.g. from "five threes" to "six threes") or the die number (e.g. "five threes" to "five sixes") or both.
A variant of "Raise" is for the player to reveal a certain number of dice that they have rolled (e.g. place 2 dice showing "fours" on the table next to their cup), reroll the remainder of the dice in the cup, and make a raised bet based on the dice that were revealed (e.g. "six fours"). For the remainder of the round, the dice that were revealed remain in play (exactly as if they were hidden under the cup, but now all players are able to see them). If a revealed die is the joker, it still counts as a joker for the other called numbers. Note that this is a different version of the game and is only used if previously agreed upon by players.
Call: If the player calls, it means that they do not buy or believe the correctness of the previous bid. The dice are shown and, if the guess is not correct (i.e. there are fewer than the number of dice showing the number called - as in the example above, only 4 dice show threes), the previous player (who made the call) loses a die. If it is correct, the player who doubted loses a die. A player with no dice remaining is eliminated from the game.[1] After calling a new round starts with the player that lost a die making a new initial call of their choice, or (if that player was eliminated) the player to that player's left.[1] The game continues until one player remains with dice.
Spot on: If a player calls spot on, this means that he or she is sure that the previous announcement is the exact guess, so the number of dice, and the face value called will be exactly correct when all are revealed. The dice are shown. If the guess was correct, the player wins a die from the table (up to the maximum five original dice). If not, the player loses a die and puts it in the bag.
Pass: If a player has five different dice in play, he or she can pass (one ace is accepted as different, but not more). The following player must raise, or say spot on for the previous bet, pass again, or call the pass if he or she thinks that the pass is a bluff. A variant allows passing if a player has a clean full house (a pair and three of a kind in one hand, aces not counting as wild cards).