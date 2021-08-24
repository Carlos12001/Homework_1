/**
 * @file fileSort.cpp
 * @version 1.5
 * @date 24/8/2021
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 * @title AED2-Homework-1
 */

#include <iostream>
#include <string>
#include <sstream>
#include "fstream"
#include "cstdio"
using namespace std;


/**
 * @author GeeksForGeeks <https://www.geeksforgeeks.org/insertion-sort/>
 * @version     1.5
 * @since       0.2
 * @brief This method implements insertion sort.
 */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


/**
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 * @version     1.5
 * @since       0.5
 * @brief This class store the basic info for the class.
 */
class Page
{
public:
    string id;
    int pos = -1;

    Page() = default;
    Page(string id)
    {
        this->id = move(id);
    }
    Page(string id, int pos)
    {
        this->id = move(id);
        this->pos = pos;
    };
};

/**
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 * @version     1.5
 * @since       0.3
 * @brief This class is the Array of pages.
 */
class PageArray
{
public:
    /**
     * Num of pages.
     */
    int n;
    /**
     * Count of numbers the pages can store.
    */
    const int size_page = 256;
    /**
     * Matrix of the page loads in memory.
     */
    int **ram = new int*[6];
    /**
     * Say is the ram is full.
     */
    bool full_ram;
    /**
     * Is the register of the page in ram.
     */
    Page mmu [12];
    /**
     * THe path of the file.
     */
    string path;
    /**
     * @brief The construct of the class.
     * @since 0.3
     * @param path The path of the file.
     */
    PageArray(string path)
    {
        this->path = move(path);
    }

private:
    /**
    * @brief Read the data of the file and return the pointer of the data.
    * @since 0.6
    * @param multiple_page The numtiple of the page.
     * @return Data read of the page.
    */
    int * readInfoPage(int multiple_page)
    {
        fstream my_file;

        string info ="";
        char index;

        int counter = 0;
        int *page =  new int [this->size_page];

        my_file.open (this->path, ios :: in);

        if (my_file.is_open())
        {
            while(!my_file.eof() && counter < this->size_page * multiple_page)
            {
                my_file >> index;

                if(index==',')
                    counter++;

                if(this->size_page * multiple_page - this->size_page <= counter)
                {
                    if (index == '1' || index =='2' || index =='3' ||
                    index == '4' || index =='5' || index =='6' ||
                    index == '7' || index =='8' || index =='9' ||
                    index == '0'){
                        info += index;
                        continue;
                    }

                    else if (index==',' && info!="")
                    {
                        *(page+((counter-1) % this->size_page)) = stoi(info);
                        info = "";
                    }

                    else
                        continue;
                }
            }
        }
        my_file.close();
        return page;
    }
    /**
    * @brief Write the data of the file.
    * @since 0.6
    * @param multiple_page The numtiple of the page.
     * @param page The page to add in the file.
    */
    void writeInfoPage(int multipler_page, int *page)
    {


        // open file in read mode or in mode
        fstream reader_writer;
        fstream append;

        reader_writer.open(this->path, ios::in | ios::out);
        append.open(this->path, ios::app);
        append << "#" << endl;

        // loop getting single characters
        int space_counter = 1, number_counter = 0;
        string info = "";
        char index;
        while(!reader_writer.eof())
        {
            reader_writer >> index;
            reader_writer.seekp(space_counter-1);
            reader_writer << "";
            space_counter ++;
            //        cout << "Index value: " << index << " Info value: " << info << " Space: "<< space_counter << endl;

            if (index=='#')
            {
                reader_writer.seekp(space_counter-2);
                reader_writer << " ";
                break;
            }
            else{
                if (index == '1' || index =='2' || index =='3' ||
                index == '4' || index =='5' || index =='6' ||
                index == '7' || index =='8' || index =='9' ||
                index == '0' )//|| (index =='-' && info==""))
                    {
                    info += index;
                    }
                else if (index==',' && info!="")
                {
                    number_counter++;
                    if(this->size_page*multipler_page-this->size_page <= number_counter && number_counter <= multipler_page*this->size_page)
                    {
                        append << *(page+(number_counter-1) % this->size_page) << ",";
                        //                    cout << page+(number_counter-1) % size_page;
                    }
                    else{
                        append << info << ",";
                        //                    cout << info;
                    }
                    //                cout << endl << "-------------------------" << endl;
                    info = "";
                }
                else{
                    NULL;
                }
            }
        }
        if(info!=""){
            append << info;
        }
        append.close();
        reader_writer.close();


        string a_string;
        string dummy;
        char delim;
        ifstream a_file (this->path);
        while (a_file >> dummy)
        {
            delim = a_file.get ();
            dummy += delim;
            a_string += dummy;
        }

        cout << a_string;

        return;
    }
};

int main()
{
}