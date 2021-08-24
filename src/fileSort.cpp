#include <iostream>
#include <string>
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

// Delete n-th line from given file
void writeInfoPage()
{
    int size_page = 5;
    string path = "sample.txt";

    int multipler_page = 4;
    int *page;
    int array []= {116, 116, 116, 116};
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
        reader_writer << " ";
        space_counter ++;

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
                if(size_page*multipler_page-size_page < number_counter && number_counter <= multipler_page*size_page)
                {
                    append << *(page+(number_counter-1) % size_page) << ",";
                }
                else{
                    append << info << ",";
                }
                info = "";
            }
            else{
                NULL;
            }
        }
    }
    reader_writer.close();
    append.close();
    //    reformartInfoPage();
    return;
}


int main()
{
    writeInfoPage();
}