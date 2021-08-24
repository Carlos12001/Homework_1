#include <iostream>
#include <string>
#include <sstream>
#include "fstream"
#include "cstdio"
using namespace std;

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

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
        if (i!=0&& i%10==0) {cout << endl;}
    }
    cout << endl;
}


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


class PageArray
{
public:
    int n;
    const int size_page = 256;
    int **ram = new int*[6];
    bool full_ram;
    Page mmu [12];
    string path;

    PageArray() = default;
    PageArray(string path)
    {
        this->path = move(path);
    }

private:
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
};


void filter_blank_spaces(ifstream& in_stream, ofstream& out_stream)
{
    char next;
    in_stream.get(next);

    do
    {
        if (isspace(next))
            out_stream << ' ';
        else
            out_stream << next;
        in_stream.get(next);
    }
    while (! in_stream.get(next));
}

// Delete n-th line from given file
void writeInfoPage()
{
    int size_page = 5;
    const char *path = "sample.txt";

    int multipler_page = 4;
    int *page;
    int array []= {1,2,3,4,5};
    page = array;



    // open file in read mode or in mode
    fstream reader_writer;
    fstream append;

    reader_writer.open(path, ios::in | ios::out);
    append.open(path, ios::app);
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
                if(size_page*multipler_page-size_page <= number_counter && number_counter <= multipler_page*size_page)
                {
                    append << *(page+(number_counter-1) % size_page) << ",";
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
    ifstream a_file (path);
    while (a_file >> dummy)
    {
        delim = a_file.get ();
        dummy += delim;
        a_string += dummy;
    }

    cout << a_string;

    return;
}


int main()
{
    writeInfoPage();
}