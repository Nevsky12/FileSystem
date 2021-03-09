#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

int main()
{

    std::string path="TheBeginning.txt";
    std::string msg="";
    std::filesystem::path file_name1{"even.txt"};
    std::filesystem::path file_name2{"odd.txt"};
    std::filesystem::path file_name3{"c.txt"};
    std::filesystem::path parent_directory{".."};
    std::filesystem::path directory{"processed"};
    std::ofstream file_out1(parent_directory/directory/file_name1);
    std::ofstream file_out2(parent_directory/directory/file_name2);
    std::ofstream file_out3(parent_directory/directory/file_name3);
    std::fstream fs,ps,ks,ms;
    fs.open(path,std::fstream::in);
    if (!fs.is_open())
    {

        std::cout<<"ERROR!"<<std::endl;

    }

    else
        {

        while (!fs.eof())
        {

            msg="";
            fs>>msg;
            int Length=msg.length();
            for (auto i: msg)
            {

                i=std::tolower(i);

            }

            bool ok=true;
            for (auto i: msg)
            {

                if (i=='c')
                {

                    i=std::toupper(i);
                    file_out3<<msg<<'\n';
                    ok=false;

                }

            }

            if (ok)
            {

                if (Length%2==0)
                {

                    file_out1<<msg<<"_"<<'\n';

                }
                else {

                    file_out2<<msg<<"_"<<'\n';

                     }

            }

            }

        }

    fs.close();
    file_out1.close();
    file_out2.close();
    file_out3.close();
    return 0;

}
