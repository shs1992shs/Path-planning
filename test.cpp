/*-----------------------------------------------*/
/*  test.cpp                                     */
/*  Main program to run and test partial parts   */
/*  Leonardo Castilho                            */
/*  Start: June 15th                             */
/*-----------------------------------------------*/


#include "obstacle.h"
#include "point.h"

using namespace std;

int main (){
  unsigned int option = 0, vertices = 0;
  vector<Obstacle*> Map;
    
     do{ //Start menu
       cout << endl;
       cout << "Select an option:" << endl;
       cout << "1 - Create new obstacle" << endl;
       cout << "2 - Number of obstacles" << endl;
       cout << "0 - Quit" << endl;
       cin >> option;
       
       switch(option){
         // =================== CASE 0 ===================
         case 0:{
           break;
         }
         // =================== CASE 1 ===================
         case 1:{
            vector<Point*> vertices_input;
            do{
               cout << "How many vertices does this object have? ";
               cin >> vertices;
               if(vertices<3) cout << "An object of are non-zero must " 
                                  << "have at least 3 vertices." << endl;
            }while(vertices < 3);
            while(vertices > 0){
              int x, y;
              cout << "Enter x y: ";
              cin >> x;
              cin >> y;
              vertices_input.push_back(new Point(x,y));
              vertices --;
            }
            Map.push_back(new Obstacle(vertices_input));
            break;
         }
         // =================== CASE 2 ===================
         case 2:{
           cout << Map.size() << " object(s)." << endl << endl;
           break;
         }
         // ================== DEFAULT ===================
         default:{
           break;
         }
       }//End switch(option)
     
     }while(option != 0);//End menu
     
     //------ Free memory ----------
     Obstacle *deleting;
     while(Map.size() != 0){ //Delete items
       deleting = Map[Map.size()-1];
       delete deleting;
       Map.pop_back();
     }
     //-----------------------------
     
  return 0;
}
