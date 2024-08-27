
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

enum class chooseplayer {
  PowerFull_Player,
  Skillfull_Player,
  Raged_Player,
  None
};

chooseplayer current_player;
chooseplayer curreny_player_2;

template <typename T> int randomrange(T min, T max) {
  return min + rand() % (max - min + 1);
}

// This is the parent class Player
class Player {
protected:
  int health; // This is the deciding factor of losing and winning
  int heal;
  const int basedamage = 25;
  double additional_damage;

public:
  Player(int health_pow, int heal_pow, double add_pow)
      : health(health_pow), heal(heal_pow), additional_damage(add_pow) {}

  virtual ~Player() = default;

  // Pure virtual functions
  virtual void takedamage(int damage) = 0;
  virtual void gethealed(int heal) = 0;
  virtual void setplayer(chooseplayer player) = 0;
  virtual int getdamage() = 0;
  virtual int takeheal() = 0;
  virtual int gethealth() = 0;
  virtual chooseplayer getplayer() = 0;
  virtual void sethealth(int h) = 0;
  virtual int getbasedamage() = 0;
  virtual void additionaldamage(Player &target) = 0;
  virtual double getadditionaldamage() = 0;
  virtual void specialability(Player &target)=0;
// the ability of the player powerfull is that he can give 2.5 times of base damage
// the ability of the player skillfull is that he can heal and also give attack
// the ability of the player is that when its health become half it can give 3x of the base damage
};

class PowerFull_Player : public Player {
public:
  int prehealth = health;
  PowerFull_Player() : Player(200, randomrange(20, 30), randomrange(50, 100)) {}

  void takedamage(int damage) override { health -= getbasedamage(); }

  void gethealed(int heal) override {
    health += heal;
     int new_health;
    new_health=health;
    if (new_health>= prehealth) {
      new_health = prehealth;
      sethealth( new_health);
    } else {
      sethealth( new_health);
    }
  }

  void setplayer(chooseplayer player) override { current_player = player; }

  void sethealth(int h) override { health = h; }

  int getdamage() override { return getbasedamage(); }

  int takeheal() override { return heal; }

  int gethealth() override { return health; }

  chooseplayer getplayer() override { return current_player; }

  int getbasedamage() override { return basedamage; }

  

  void additionaldamage(Player &target) override {
    target.sethealth(target.gethealth() - additional_damage);
  }

  double getadditionaldamage() override { return additional_damage; }


void specialability(Player &target) override{
  int prob=0;
   prob= rand()%2;
  static int count=0;
  if(prob==1){
    target.sethealth(target.gethealth()-static_cast<float>(basedamage*2.5));
  if(target.gethealth()<0){
    target.sethealth(0);
  }else{
    cout<<" NOW THE HEALTH OF ENEMY PLAYER IS "<<target.gethealth()<<endl;
    count++;
    if(count>=20){
      cout<<"NOW LIMIT CROSSED CANT USE THE ABILITY"<<endl;
    }
  }
  }else if(count==0){
    cout<<"PLEASE TRY YOUR LUCK NEXT TIME"<<endl<<endl;
  }
}


};

class Skillfull_Player : public Player {
private:
  int pre_health = health;

public:
  Skillfull_Player() : Player(100, randomrange(10, 20), randomrange(10, 50)) {}

  void takedamage(int damage) override {
    pre_health = health;
    health -= getbasedamage();
    sethealth(health);
  }

  void gethealed(int heal) override {
    health += heal;
     int new_health;
    new_health=health;
    if (new_health>= pre_health) {
      new_health = pre_health;
      sethealth( new_health);
    } else {
      sethealth( new_health);
    }
  }

  void setplayer(chooseplayer player) override { current_player = player; }

  void sethealth(int h) override { health = h; }

  int getdamage() override { return getbasedamage(); }

  int takeheal() override { return heal; }

  int gethealth() override { return health; }

  chooseplayer getplayer() override { return current_player; }

  int getbasedamage() override { return basedamage; }
  void additionaldamage(Player &target) override {
    target.sethealth(target.gethealth() - additional_damage);
  }

  double getadditionaldamage() override { return additional_damage; }

void specialability(Player &target) override{
  int prob=0;
   prob= rand()%2;
  int new_heal= takeheal()*2;
  static int count=0;
  if(prob==1){
    gethealed(new_heal);
    target.sethealth(target.gethealth()-basedamage);
      if(target.gethealth()<0){
        target.sethealth(0);
        
      }else{
        cout<<" YOUR HEALTH IS "<<gethealth()<<endl;
    cout<<"THE ENEMY HEALTH IS "<<target.gethealth()<<endl;
    count++;
    if(count>=20){
      cout<<"NOW LIMIT CROSSED CANT USE THE ABILITY"<<endl;
    }
      }
  }else if(count==0){
    cout<<"PLEASE TRY YOUR LUCK NEXT TIME"<<endl<<endl;
  }
  
}

};

class Raged_Player : public Player {
private:
  int pre_health=health;;

public:
  Raged_Player() : Player(150, randomrange(10, 20), randomrange(50, 80)) {}

  void takedamage(int damage) override { sethealth(health - getdamage()); }

  void gethealed(int heal) override {
    health += heal;
     int new_health;
    new_health=health;
    if (new_health>= pre_health) {
      new_health = pre_health;
      sethealth( new_health);
    } else {
      sethealth( new_health);
    }
  }

  void setplayer(chooseplayer player) override { current_player = player; }

  void sethealth(int h) override { health = h; }

  int getdamage() override { return getbasedamage(); }

  int takeheal() override { return heal; }

  int gethealth() override { return health; }

  chooseplayer getplayer() override { return current_player; }

  int getbasedamage() override { return basedamage; }



  void additionaldamage(Player &target) override {
    target.sethealth(target.gethealth() - additional_damage);
  }

  double getadditionaldamage() override { return additional_damage; }



void specialability(Player &target) override{
  int prob=0;
   prob= rand()%2;
  static int count=0;
  if(prob==1){
    if(gethealth()<gethealth()%2){
      target.sethealth(target.gethealth()-basedamage*3);
    if(target.gethealth()<0){
      target.sethealth(0);
      
    }else{ 
      count++;
      if(count==0){
        cout<<"YOU CROSSED THE LIMIT CANT USE THE ABILITY"<<endl;
      }
    else{
      cout<<" YOU CANT USE THE ABILITY YOUR HEALTH IS GOOD "<<endl;
    }
    }
    
  
  }else if(count==0){
    cout<<"PLEASE TRY YOUR LUCK NEXT TIME"<<endl<<endl;
  }
  }
}

};

// This function is used to get the player chosen
string enumToString(chooseplayer player) {
  switch (player) {
  case chooseplayer::PowerFull_Player:
    return "PowerFull Player";
  case chooseplayer::Skillfull_Player:
    return "Skillfull Player";
  case chooseplayer::Raged_Player:
    return "Raged Player";
  case chooseplayer::None:
  default:
    return "None";
  }
}

int main() {
  srand(time(0));

  Player *p1 = nullptr;
  Player *p2 = nullptr;

  cout << "WELCOME TO THE WAJI GAME" << endl;
  cout << "HEY BIG BROTHER, CHOOSE YOUR PLAYER 1 FOR FIGHT" << endl;
  cout << "PRESS 1 FOR POWERFULL PLAYER" << endl;
  cout << "PRESS 2 FOR SKILLFULL PLAYER" << endl;
  cout << "PRESS 3 FOR RAGED PLAYER" << endl<<endl;
  int choice_one;
  cin >> choice_one;
  switch (choice_one) {
  case 1:
    p1 = new PowerFull_Player();
    current_player = chooseplayer::PowerFull_Player;
    p1->setplayer(chooseplayer::PowerFull_Player);
    cout << "BROTHER YOU SELECTED POWERFULL PLAYER" << endl;
    cout << "BIG BROTHER I WILL FIGHT TILL THEY GET DESTROYED" << endl;
    cout << "MY HEALTH IS " << p1->gethealth() << endl;
    cout << "MY HEAL IS " << p1->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p1->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p1->getadditionaldamage() << endl<<endl;
    break;

  case 2:
    p1 = new Skillfull_Player();
    current_player = chooseplayer::Skillfull_Player;
    p1->setplayer(chooseplayer::Skillfull_Player);
    cout << "BROTHER YOU SELECTED SKILLFULL PLAYER" << endl;
    cout << "BIG BROTHER I WILL BE WITH YOU TILL END" << endl;
    cout << "MY HEALTH IS " << p1->gethealth() << endl;
    cout << "MY HEAL IS " << p1->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p1->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p1->getadditionaldamage()<< endl<<endl;
    
    break;

  case 3:
    p1 = new Raged_Player();
    current_player = chooseplayer::Raged_Player;
    p1->setplayer(chooseplayer::Raged_Player);
    cout << "BROTHER YOU SELECTED RAGED PLAYER" << endl;
    cout << "BIG BROTHER I AM FULL OF RAGE, LET'S DUCK THEM" << endl;
    cout << "MY HEALTH IS " << p1->gethealth() << endl;
    cout << "MY HEAL IS " << p1->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p1->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p1->getadditionaldamage() << endl<<endl;
    break;

  default:
    p1 = nullptr;
    current_player = chooseplayer::None;
    cout << "NO PLAYER SELECTED. EXITING..." << endl;
    return 1;
  }

  // Player 2 selection (same as above)
  cout << "HEY BIG DAWG CHOOSE YOUR PLAYER 2 FOR FIGHT" << endl;
  cout << "PRESS 1 FOR POWERFULL PLAYER" << endl;
  cout << "PRESS 2 FOR SKILLFULL PLAYER" << endl;
  cout << "PRESS 3 FOR RAGED PLAYER" << endl<<endl;
  int choice_two;
  cin >> choice_two;
  switch (choice_two) {
  case 1:
    p2 = new PowerFull_Player();
    curreny_player_2 = chooseplayer::PowerFull_Player;
    p2->setplayer(chooseplayer::PowerFull_Player);
    cout << "YOU SELECTED POWERFULL PLAYER FOR PLAYER 2" << endl;
    cout << "MY HEALTH IS " << p2->gethealth() << endl;
    cout << "MY HEAL IS " << p2->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p2->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p2->getadditionaldamage() << endl<<endl;
    break;

  case 2:
    p2 = new Skillfull_Player();
    curreny_player_2 = chooseplayer::Skillfull_Player;
    p2->setplayer(chooseplayer::Skillfull_Player);
    cout << "YOU SELECTED SKILLFULL PLAYER FOR PLAYER 2" << endl;
    cout << "MY HEALTH IS " << p2->gethealth() << endl;
    cout << "MY HEAL IS " << p2->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p2->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p2->getadditionaldamage() << endl<<endl;
break;
  case 3:
    p2 = new Raged_Player();
    curreny_player_2 = chooseplayer::Raged_Player;
    p2->setplayer(chooseplayer::Raged_Player);
    cout << "YOU SELECTED RAGED PLAYER FOR PLAYER 2" << endl;
    cout << "MY HEALTH IS " << p2->gethealth() << endl;
    cout << "MY HEAL IS " << p2->takeheal() << endl;
    cout << "MY BASE DAMAGE IS " << p2->getdamage() << endl;
    cout << "MY ADDITIONAL DAMAGE IS " << p2->getadditionaldamage() << endl<<endl;
    break;

  default:
    p2 = nullptr;
    curreny_player_2 = chooseplayer::None;
    cout << "NO PLAYER SELECTED. EXITING..."<< endl<<endl;
    return 1;
  }

  char p1_choice, p2_choice;
  ;
  cout << "ITS THE TURN OF THE BIG BROTHER" << endl << endl;
  cout << "PRESS A FOR ATTACK CAUSE ITS THE FIRST TURN" << endl<<endl;

  cin >> p1_choice;
  p1_choice = toupper(p1_choice);
  if (p1_choice == 'A') {
    p2->takedamage(p1->getdamage());
    cout << "THE HEALTH OF THE BIG DAWG IS " << p2->gethealth() << endl<<endl;
  }
  cout << "YEAH BIG DAWG WILL TAKE REVENGE"<< endl<<endl;
  cin >> p2_choice;
  p2_choice = toupper(p2_choice);
  if (p2_choice == 'A') {
    p1->takedamage(p2->getdamage());
    ;
    cout << "BIG BROTHER HEALTH IS " << p1->gethealth() << endl<<endl;
  }
  cout << "BIG BROTHER HEALING  YOU CAN USE H FOR HEALING AND S FOR SPECIAL "
          "Ability AND HEAVY ATTACK USE X"
      << endl<<endl;

  cout << "SAME GOES FOR YOU BIG DAWG IF YOUR HEALTH IS LOW USE HEAL OR "
          "SPECIAL ABILITY"<< endl<<endl;

  while (p1->gethealth() > 0 && p2->gethealth() > 0) {
    cout << "ITS THE TURN OF THE BIG BROTHER DO WHAT YOU WANT TO DO" << endl << endl;
    cin >> p1_choice;
    p1_choice = toupper(p1_choice);

    switch (p1_choice) {
    case 'A': {
        p2->takedamage(p1->getdamage());
        if (p2->gethealth() <= 0) {
            p2->sethealth(0);
            cout << "THE HEALTH OF BIG DAWG " << p2->gethealth() << endl;
            break;
        } else {
            cout << "THE HEALTH OF THE BIG DAWG " << p2->gethealth() << endl << endl;
        }
        break;
    }
    case 'H':
        p1->gethealed(p1->takeheal());
        cout << "NOW THE HEALTH OF THE BIG BROTHER IS " << p1->gethealth() << endl << endl;
        break;

    case 'X': {
        p1->additionaldamage(*p2);
        if (p2->gethealth() <= 0) {
            p2->sethealth(0);
            cout << "THE HEALTH OF THE BIG DAWG " << p2->gethealth() << endl << endl;
            break;
        } else {
            cout << "THE HEALTH OF THE BIG DAWG IS " << p2->gethealth() << endl << endl;
        }
        break;
    }
    case 'S': {
        p1->specialability(*p2);
        if (p2->gethealth() <= 0) {
            p2->sethealth(0);
            cout << "THE HEALTH OF THE BIG DAWG " << p2->gethealth() << endl << endl;
            break;
        } else {
            cout << "THE HEALTH OF THE BIG DAWG " << p2->gethealth() << endl << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    if (p2->gethealth() <= 0) {
        break; // End loop if Big Dawg's health is zero
    }

    cout << "YEAH BIG DAWG WILL TAKE REVENGE" << endl;
    cin >> p2_choice;
    p2_choice = toupper(p2_choice);

    switch (p2_choice) {
    case 'A': {
        p1->takedamage(p2->getdamage());
        if (p1->gethealth() <= 0) {
            p1->sethealth(0);
            cout << "THE HEALTH OF THE BIG BROTHER IS " << p1->gethealth() << endl;
            break;
        } else {
            cout << "THE HEALTH OF THE BIG BROTHER IS " << p1->gethealth() << endl;
        }
        break;
    }
    case 'H': {
        p2->gethealed(p2->takeheal());
        cout << "THE HEALTH OF THE BIG DAWG IS " << p2->gethealth() << endl;
        break;
    }
    case 'X': {
        p2->additionaldamage(*p1);
        if (p1->gethealth() <= 0) {
            p1->sethealth(0);
            cout << "THE HEALTH OF THE BIG BROTHER BECOME " << p1->gethealth() << endl;
            break;
        } else {
            cout << "NOW THE HEALTH OF THE BIG BROTHER IS " << p1->gethealth() << endl;
        }
        break;
    }
    case 'S': {
        p2->specialability(*p1);
        if (p1->gethealth() <= 0) {
            p1->sethealth(0);
            break;
        }
        break;
    }
    default:
        cout << "INVALID CHOICE" << endl;
        break;
    }

    if (p1->gethealth() <= 0) {
        break; // End loop if Big Brother's health is zero
    }
  }

  if (p1->gethealth() <= 0) {
    cout << "BIG DAWG WON THE FIGHT" << endl;
  } else if (p2->gethealth() <= 0) {
    cout << "BIG BROTHER WON THE FIGHT" << endl;
  }

  delete p1;
  delete p2;

  return 0;
}
