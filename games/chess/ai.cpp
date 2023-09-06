// AI
// This is where you build your AI

#include "ai.hpp"

// You can add #includes here for your AI.

namespace cpp_client
{

namespace chess
{

/// <summary>
/// This returns your AI's name to the game server.
/// Replace the string name.
/// </summary>
/// <returns>The name of your AI.</returns>
std::string AI::get_name() const
{
    // REPLACE WITH YOUR TEAM NAME!
    return "Fragile Fig";
}

/// <summary>
/// This is automatically called when the game first starts, once the game objects are created
/// </summary>
void AI::start()
{
    // This is a good place to initialize any variables
    srand(time(NULL));
}

/// <summary>
/// This is automatically called the game (or anything in it) updates
/// </summary>
void AI::game_updated()
{
    // If a function you call triggers an update this will be called before it returns.
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if you won, false otherwise</param>
/// <param name="reason">An explanation for why you either won or lost</param>
void AI::ended(bool won, const std::string& reason)
{
    // You can do any cleanup of your AI here.  The program ends when this function returns.
}

/// <summary>
/// This is called every time it is this AI.player's turn.
/// </summary>
/// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
bool AI::run_turn()
{
    // Here is where you'll want to code your AI.

    // We've provided sample code that:
    //    1) prints the board to the console
    //    2) prints the opponent's last move to the console
    //    3) prints how much time remaining this AI has to calculate moves
    //    4) makes a random (and probably invalid) move.

    // 1) print the board to the console
    print_current_board();

    // 2) print the opponent's last move to the console
    if(game->moves.size() > 0)
    {
        std::cout << "Opponent's Last Move: '" << game->moves[game->moves.size() - 1]->san << "'" << std::endl;
    }

    // 3) print how much time remaining this AI has to calculate moves
    std::cout << "Time Remaining: " << player->time_remaining << " ns" << std::endl;

    // 4) make a random (and probably invalid) move.
    //chess::Piece random_piece = player->pieces[rand() % player->pieces.size()];
    //std::string random_file(1, 'a' + rand() % 8);
    //int random_rank = (rand() % 8) + 1;
    //random_piece->move(random_file, random_rank);

    //return true; // to signify we are done with our turn.
    /*std::string code;
    std::string mboard[8][8];
    for(const auto& piece : game->pieces){
        code = current_piece->type[0];
        if(current_piece->type == "Knight"){
            code = "N";
        }
    }*/

    int calc = 1;
    if(player->color=="Black"){
        calc=-1;
    }
    int locale = 0;
    bool good = true;
    int mranks[100];
    std::string mleft;
    std::string mright;
    std::string mright2;
    std::string mleft2;
    std::string mfiles[100];
    chess::Piece mpieces[100];
    for(const auto& p : player->pieces){
        good = true;
        mleft = "";
        mright = "";
        mleft2 = "";
        mright2 = "";
        if(p->file=="a"){
            mright="b";
            mright2="c";
        }else if(p->file=="b"){
            mleft="a";
            mright="c";
            mright2="d";
        }else if(p->file=="c"){
            mleft2="a";
            mleft="b";
            mright="d";
            mright2="e";
        }else if(p->file=="d"){
            mleft2="b";
            mleft="c";
            mright="e";
            mright2="f";
        }else if(p->file=="e"){
            mleft2="c";
            mleft="d";
            mright="f";
            mright2="g";
        }else if(p->file=="f"){
            mleft2="d";
            mleft="e";
            mright="g";
            mright2="h";
        }else if(p->file=="g"){
            mleft2="e";
            mleft="f";
            mright="h";
        }else if(p->file=="h"){
            mleft2="f";
            mleft="g";
        }
        if(p->type=="Pawn"){
            if(!(p->has_moved) && ((player->color=="White" && p->rank==2) || (player->color=="Black" && p->rank==7))){
                for(const auto& piece : game->pieces){
                    if(piece->file == p->file && piece->rank == p->rank+(calc*2)){
                        good = false;
                    }
                    if(piece->file == p->file && piece->rank == p->rank+(calc*1)){
                        good = false;
                    }
                }
                if(good){
                    mranks[locale]=p->rank+(2*calc);
                    mfiles[locale]=p->file;
                    mpieces[locale]=p;
                    locale++;
                    std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
            }

            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == p->file && piece->rank == p->rank+(calc*1) && p->rank+(calc*1)<9 && p->rank+(calc*1)>0){
                    good = false;
                }
            }
            if(good){
                mranks[locale]=p->rank+(1*calc);
                mfiles[locale]=p->file;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            good = false;
            if(true){
                for(const auto& piece : game->pieces){
                    if(piece->file == mleft && piece->rank == p->rank+(calc*1) && mleft!="" && piece->owner==player->opponent){
                        good = true;
                    }
                }
                if(good){
                    mranks[locale]=p->rank+(1*calc);
                    mfiles[locale]=mleft;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
            }

            good=false;
            if(true){
                for(const auto& piece : game->pieces){
                    if(piece->file == mright && piece->rank == p->rank+(calc*1) && mright!="" && piece->owner==player->opponent){
                        good = true;
                    }
                }
                if(good){
                    mranks[locale]=p->rank+(1*calc);
                    mfiles[locale]=mright;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
            }


        }//end Pawn
        else if(p->type=="Knight"){

            mleft = "";
            mright = "";
            mleft2 = "";
            mright2 = "";
            if(p->file=="a"){
                mright="b";
                mright2="c";
            }else if(p->file=="b"){
                mleft="a";
                mright="c";
                mright2="d";
            }else if(p->file=="c"){
                mleft2="a";
                mleft="b";
                mright="d";
                mright2="e";
            }else if(p->file=="d"){
                mleft2="b";
                mleft="c";
                mright="e";
                mright2="f";
            }else if(p->file=="e"){
                mleft2="c";
                mleft="d";
                mright="f";
                mright2="g";
            }else if(p->file=="f"){
                mleft2="d";
                mleft="e";
                mright="g";
                mright2="h";
            }else if(p->file=="g"){
                mleft2="e";
                mleft="f";
                mright="h";
            }else if(p->file=="h"){
                mleft2="f";
                mleft="g";
            }

            //up 2 right 1
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mright && piece->rank == p->rank+2 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank+2>8){
                good=false;
            }
            if(mright==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank+2;
                mfiles[locale]=mright;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //up 1 right 2
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mright2 && piece->rank == p->rank+1 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank+1>8){
                good=false;
            }
            if(mright2==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank+1;
                mfiles[locale]=mright2;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //down 1 right 2
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mright2 && piece->rank == p->rank-1 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank-1<1){
                good=false;
            }
            if(mright2==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank-1;
                mfiles[locale]=mright2;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //down 2 right 1
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mright && piece->rank == p->rank-2 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank-2<1){
                good=false;
            }
            if(mright==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank-2;
                mfiles[locale]=mright;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //down 2 left 1
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mleft && piece->rank == p->rank-2 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank-2<1){
                good=false;
            }
            if(mleft==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank-2;
                mfiles[locale]=mleft;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //down 1 left 2
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mleft2 && piece->rank == p->rank-1 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank-1<1){
                good=false;
            }
            if(mleft2==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank-1;
                mfiles[locale]=mleft2;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //up 1 left 2
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mleft2 && piece->rank == p->rank+1 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank+1>8){
                good=false;
            }
            if(mleft2==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank+1;
                mfiles[locale]=mleft2;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            //up 2 left 1
            good=true;
            for(const auto& piece : game->pieces){
                if(piece->file == mleft && piece->rank == p->rank+2 && piece->owner->color==player->color){
                    good=false;
                }
            }
            if(p->rank+2>8){
                good=false;
            }
            if(mleft==""){
                good=false;
            }
            if(good){
                mranks[locale]=p->rank+2;
                mfiles[locale]=mleft;
                mpieces[locale]=p;
                locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

        }//end knight
        else if(p->type=="Rook"){
            //up
            for(int i = p->rank+1;i<=8;i++){
                good=true;
                bool fin = false;
                bool fin2 = false;
                for(const auto& piece : game->pieces){
                    if(piece->file == p->file && piece->rank == i && piece->owner==player){
                        good = false;
                        fin=true;
                    }else if(piece->file == p->file && piece->rank == i && piece->owner!=player){
                        fin2=true;
                    }
                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=i;
                    mfiles[locale]=p->file;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }

            //down
            for(int i = p->rank-1;i>=1;i--){
                good=true;
                bool fin=false;
                bool fin2 = false;
                for(const auto& piece : game->pieces){
                    if(piece->file == p->file && piece->rank == i && piece->owner==player){
                        good = false;
                        fin=true;
                    }else if(piece->file == p->file && piece->rank == i && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=i;
                    mfiles[locale]=p->file;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                 }
                if(fin2){
                    break;
                }

            }

            //right
            std::string ffile = " ";
            char ftem = p->file[0];
            int ftemp = (int)ftem;
            for(int i = ftemp+1; i<105;i++){
                bool fin=false;
                bool fin2 = false;
                good=true;
                ftem = (char)i;
                ffile[0]=ftem;
                for(const auto& piece : game->pieces){
                    if(piece->file == ffile && piece->rank == p->rank && piece->owner==player){
                        good = false;
                        fin = true;
                    }else if(piece->file == ffile && piece->rank == p->rank && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=p->rank;
                    mfiles[locale]=ffile;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }

            //left
            for(char i = ftemp-1; i>96;i--){
                bool fin = false;
                bool fin2 = false;
                good=true;
                ftem = (char)i;
                ffile[0]=ftem;
                for(const auto& piece : game->pieces){
                    if(piece->file == ffile && piece->rank == p->rank && piece->owner==player){
                        good = false;
                        fin = true;
                    }else if(piece->file == ffile && piece->rank == p->rank && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=p->rank;
                    mfiles[locale]=ffile;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }
        }//end Rook
        else if(p->type=="Bishop"){
            //up right
            std::string ffile = " ";
            char ftem = p->file[0];
            int ftemp = (int)ftem;
            ffile[0] = ftemp;
            char ftem2;
            bool ur1 = true;
            bool ur2 = true;
            bool dr1 = true;
            bool dr2 = true;
            bool dl1 = true;
            bool dl2 = true;
            bool ul1 = true;
            bool ul2 = true;
            for(int i=1;i<8;i++){

                for(const auto& piece : game->pieces){

                    //ur
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank+i && piece->owner==player){
                        ur1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank+i && piece->owner!=player){
                        if(ur1 && ur2){
                            ur2=false;
                            ftem2=(char)(ftemp+i);
                            ffile[0]=ftem2;
                            if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank+i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                               std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }

                    //dr
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank-i && piece->owner==player){
                        dr1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank-i && piece->owner!=player){
                        if(dr1 && dr2){
                            dr2=false;
                            ftem2=(char)(ftemp+i);
                            ffile[0]=ftem2;
                            if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank-i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                               std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }

                    //dl
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank-i && piece->owner==player){
                        dl1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank-i && piece->owner!=player){
                        if(dl1 && dl2){
                            dl2=false;
                            ftem2=(char)(ftemp-i);
                            ffile[0]=ftem2;
                            if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank-i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }

                    //ul
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank+i && piece->owner==player){
                        ul1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank+i && piece->owner!=player){
                        if(ul1 && ul2){
                            ul2=false;
                            ftem2=(char)(ftemp-i);
                            ffile[0]=ftem2;
                            if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank+i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }
                }

                //ur
                if(ur1 && ur2){
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank+i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //dr
                if(dr1 && dr2){
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank-i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //dl
                if(dl1 && dl2){
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank-i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //ul
                if(ul1 && ul2){
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank+i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }

            }

        }//end Bishop
        else if(p->type=="Queen"){
            //-----------------------Straight----------------------
            //up
            for(int i = p->rank+1;i<=8;i++){
                good=true;
                bool fin = false;
                bool fin2 = false;
                for(const auto& piece : game->pieces){
                    if(piece->file == p->file && piece->rank == i && piece->owner==player){
                        good = false;
                        fin=true;
                    }else if(piece->file == p->file && piece->rank == i && piece->owner!=player){
                        fin2=true;
                    }
                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=i;
                    mfiles[locale]=p->file;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }

            //down
            for(int i = p->rank-1;i>=1;i--){
                good=true;
                bool fin=false;
                bool fin2 = false;
                for(const auto& piece : game->pieces){
                    if(piece->file == p->file && piece->rank == i && piece->owner==player){
                        good = false;
                        fin=true;
                    }else if(piece->file == p->file && piece->rank == i && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=i;
                    mfiles[locale]=p->file;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                 }
                if(fin2){
                    break;
                }

            }

            //right
            std::string ffile = " ";
            char ftem = p->file[0];
            int ftemp = (int)ftem;
            for(int i = ftemp+1; i<105;i++){
                bool fin=false;
                bool fin2 = false;
                good=true;
                ftem = (char)i;
                ffile[0]=ftem;
                for(const auto& piece : game->pieces){
                    if(piece->file == ffile && piece->rank == p->rank && piece->owner==player){
                        good = false;
                        fin = true;
                    }else if(piece->file == ffile && piece->rank == p->rank && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=p->rank;
                    mfiles[locale]=ffile;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }

            //left
            for(char i = ftemp-1; i>96;i--){
                bool fin = false;
                bool fin2 = false;
                good=true;
                ftem = (char)i;
                ffile[0]=ftem;
                for(const auto& piece : game->pieces){
                    if(piece->file == ffile && piece->rank == p->rank && piece->owner==player){
                        good = false;
                        fin = true;
                    }else if(piece->file == ffile && piece->rank == p->rank && piece->owner!=player){
                        fin2=true;
                    }

                }
                if(fin){
                    break;
                }
                if(good){
                    mranks[locale]=p->rank;
                    mfiles[locale]=ffile;
                    mpieces[locale]=p;
                    locale++;
                   std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                }
                if(fin2){
                    break;
                }

            }

            //------------------------Diagonal----------------------
            //up right
            ffile = " ";
            ftem = p->file[0];
            ftemp = (int)ftem;
            ffile[0] = ftemp;
            char ftem2;
            bool ur1 = true;
            bool ur2 = true;
            bool dr1 = true;
            bool dr2 = true;
            bool dl1 = true;
            bool dl2 = true;
            bool ul1 = true;
            bool ul2 = true;
            for(int i=1;i<8;i++){

                for(const auto& piece : game->pieces){

                    //ur
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank+i && piece->owner==player){
                        ur1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank+i && piece->owner!=player){
                        if(ur1 && ur2){
                            ur2=false;
                            ftem2=(char)(ftemp+i);
                            ffile[0]=ftem2;
                            if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank+i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                               std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }

                    //dr
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank-i && piece->owner==player){
                        dr1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank-i && piece->owner!=player){
                        if(dr1 && dr2){
                            dr2=false;
                            ftem2=(char)(ftemp+i);
                            ffile[0]=ftem2;
                            if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank-i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                               std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }


                    //dl
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank-i && piece->owner==player){
                        dl1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank-i && piece->owner!=player){
                        if(dl1 && dl2){
                            dl2=false;
                            ftem2=(char)(ftemp-i);
                            ffile[0]=ftem2;
                            if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank-i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }

                    //ul
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(piece->file == ffile && piece->rank == p->rank+i && piece->owner==player){
                        ul1=false;
                    }else if(piece->file == ffile && piece->rank == p->rank+i && piece->owner!=player){
                        if(ul1 && ul2){
                            ul2=false;
                            ftem2=(char)(ftemp-i);
                            ffile[0]=ftem2;
                            if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                                mranks[locale]=p->rank+i;
                                mfiles[locale]=ffile;
                                mpieces[locale]=p;
                                locale++;
                                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                            }
                        }
                    }
                }


                //ur
                if(ur1 && ur2){
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank+i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //dr
                if(dr1 && dr2){
                    ftem2=(char)(ftemp+i);
                    ffile[0]=ftem2;
                    if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank-i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //dl
                if(dl1 && dl2){
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(p->rank-i>0 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank-i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }
                //ul
                if(ul1 && ul2){
                    ftem2=(char)(ftemp-i);
                    ffile[0]=ftem2;
                    if(p->rank+i<9 && (ffile=="a" || ffile=="b" || ffile=="c" || ffile=="d" || ffile=="e" || ffile=="f" || ffile=="g" || ffile=="h")){
                        mranks[locale]=p->rank+i;
                        mfiles[locale]=ffile;
                        mpieces[locale]=p;
                        locale++;
                        std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
                    }
                }

            }

        }//end Queen
        else if(p->type == "King"){

            bool u=true;
            bool ur=true;
            bool r=true;
            bool dr=true;
            bool d=true;
            bool dl=true;
            bool l=true;
            bool ul=true;

            std::string kcast = "g";
            std::string qcast = "c";

            mleft = "";
            mright = "";
            if(p->file=="a"){
                mright="b";
            }else if(p->file=="b"){
                mleft="a";
                mright="c";
            }else if(p->file=="c"){
                mleft="b";
                mright="d";
            }else if(p->file=="d"){
                mleft="c";
                mright="e";
            }else if(p->file=="e"){
                mleft="d";
                mright="f";
            }else if(p->file=="f"){
                mleft="e";
                mright="g";
            }else if(p->file=="g"){
                mleft="f";
                mright="h";
            }else if(p->file=="h"){
                mleft="g";
            }

            for(const auto& piece : game->pieces){
                if(piece->file == p->file && piece->rank == p->rank+1 && piece->owner->color==player->color){
                    u=false;
                }
                if(piece->file == mright && piece->rank == p->rank+1 && piece->owner->color==player->color){
                    ur=false;
                }
                if(piece->file == mright && piece->rank == p->rank && piece->owner->color==player->color){
                    r=false;
                }
                if(piece->file == mright && piece->rank == p->rank-1 && piece->owner->color==player->color){
                    dr=false;
                }
                if(piece->file == p->file && piece->rank == p->rank-1 && piece->owner->color==player->color){
                    d=false;
                }
                if(piece->file == mleft && piece->rank == p->rank-1 && piece->owner->color==player->color){
                    dl=false;
                }
                if(piece->file == mleft && piece->rank == p->rank && piece->owner->color==player->color){
                    l=false;
                }
                if(piece->file == mleft && piece->rank == p->rank+1 && piece->owner->color==player->color){
                    ul=false;
                }
            }

            if(u && p->rank+1<9){
                mranks[locale]=p->rank+1;
                mfiles[locale]=p->file;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(ur && p->rank+1<9){
                mranks[locale]=p->rank+1;
                mfiles[locale]=mright;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(r){
                mranks[locale]=p->rank;
                mfiles[locale]=mright;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(dr && p->rank-1>0){
                mranks[locale]=p->rank-1;
                mfiles[locale]=mright;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(d && p->rank-1>0){
                mranks[locale]=p->rank-1;
                mfiles[locale]=p->file;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(dl && p->rank-1>0){
                mranks[locale]=p->rank-1;
                mfiles[locale]=mleft;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(l){
                mranks[locale]=p->rank;
                mfiles[locale]=mleft;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }
            if(ul && p->rank+1<9){
                mranks[locale]=p->rank+1;
                mfiles[locale]=mleft;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            char chold;
            int j = 0;
            int k = 0;
            while(k<4){
                char chold = game->fen[j];
                if(chold==' '){
                    k++;
                }
                j++;
            }

            if(player->color=="White" && chold=='K'){
                mranks[locale]=p->rank;
                mfiles[locale]=kcast;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" Castle "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            if(player->color=="White" && chold=='Q'){
                mranks[locale]=p->rank;
                mfiles[locale]=qcast;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" Castle "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            if(player->color=="Black" && chold=='k'){
                mranks[locale]=p->rank;
                mfiles[locale]=kcast;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" Castle "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

            if(player->color=="Black" && chold=='q'){
                mranks[locale]=p->rank;
                mfiles[locale]=qcast;
                mpieces[locale]=p;
                locale++;
                std::cout<<p->type<<" Castle "<<p->file<<p->rank<<" to "<<mfiles[locale-1]<<mranks[locale-1]<<std::endl;
            }

        }//end King

    }//end all

    int mmove = (rand() % locale);
    if(mpieces[mmove]->type=="Pawn" && (mranks[mmove]==8 || mranks[mmove]==1)){
         mpieces[mmove]->move(mfiles[mmove] , mranks[mmove], "Queen");
    }else{
         mpieces[mmove]->move(mfiles[mmove] , mranks[mmove]);
    }
    if(player->in_check){
        return false;
    }
    return true;

}

/// <summary>
///  Prints the current board using pretty ASCII art
/// </summary>
/// <remarks>
/// Note: you can delete this function if you wish
/// </remarks>
void AI::print_current_board()
{
    for(int rank = 9; rank >= -1; rank--)
    {
        std::string str = "";
        if(rank == 9 || rank == 0) // then the top or bottom of the board
        {
            str = "   +------------------------+";
        }
        else if(rank == -1) // then show the ranks
        {
            str = "     a  b  c  d  e  f  g  h";
        }
        else // board
        {
            str += " ";
            str += std::to_string(rank);
            str += " |";
            // fill in all the files with pieces at the current rank
            for(int file_offset = 0; file_offset < 8; file_offset++)
            {
                std::string file(1, 'a' + file_offset); // start at a, with with file offset increasing the char;
                chess::Piece current_piece = nullptr;
                for(const auto& piece : game->pieces)
                {
                    if(piece->file == file && piece->rank == rank) // then we found the piece at (file, rank)
                    {
                        current_piece = piece;
                        break;
                    }
                }

                char code = '.'; // default "no piece";
                if(current_piece != nullptr)
                {
                    code = current_piece->type[0];

                    if(current_piece->type == "Knight") // 'K' is for "King", we use 'N' for "Knights"
                    {
                        code = 'N';
                    }

                    if(current_piece->owner->id == "1") // the second player (black) is lower case. Otherwise it's upppercase already
                    {
                        code = tolower(code);
                    }
                }

                str += " ";
                str += code;
                str += " ";
            }

            str += "|";
        }

        std::cout << str << std::endl;
    }
}
// You can add additional methods here for your AI to call

} // chess

} // cpp_client
