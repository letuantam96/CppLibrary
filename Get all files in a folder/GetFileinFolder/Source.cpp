#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
   WIN32_FIND_DATA search_data;

   memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

   HANDLE handle = FindFirstFile("C:\\opencv/*.*", &search_data);
   /*
   Replace *.* with: *.jpg to find all .jpg file in folder
					 *.png to find all .png file in forlder
					 *.* to find all file
	*/
  
   while(handle != INVALID_HANDLE_VALUE)
   {
    cout << search_data.cFileName << endl;
      if(FindNextFile(handle, &search_data) == FALSE)
        break;
   }


   return 0;
}