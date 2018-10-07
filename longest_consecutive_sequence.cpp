#include <iostream>
#include <vector>

using namespace std;

int get_longest_consecutive_sequence(const vector<int>&);

int main(){
    int n;
    vector<int> my_vector;

    while (cin >> n)
        my_vector.push_back(n);

    cout << "Max Length = " << get_longest_consecutive_sequence(my_vector) << endl;

    return 0;
}

int get_longest_consecutive_sequence(const vector<int>& my_vector){
    // get max of the my_vector
    int max = my_vector[0];
    for(vector<int>::const_iterator iter = my_vector.begin(); iter != my_vector.end(); iter++)
        if (*iter > max)
            max = *iter;

    int arr[max + 1] = {0};
    for(vector<int>::const_iterator iter = my_vector.begin(); iter != my_vector.end(); iter++)
        arr[*iter]++;

//    cout << "Array's length = " << sizeof(arr) / sizeof(int) << endl;
//
//    for(int i = 0; i < max; i++){
//        cout << arr[i] << ' ';
//        if (i % 10 == 0)
//            cout << endl;
//    }
//    cout << endl;
//    cout << "------------------------------------" << endl;

    int max_len = 0;
    int measure_len = 0;
    int max_start_index = 0;
    //int max_end_index = 0;
    int measure_start_index = 0;
    //int measure_end_index = 0;
    for (int i = 0; i < max + 1; i++){
        if (arr[i])
            measure_len++;
        else{
            if (measure_len > max_len){
                //cout << "Now start = " << measure_start_index << endl;
                //cout << "Now len = " << measure_len << endl;
                max_start_index = measure_start_index;
                //max_end_index = measure_end_index;
                max_len = measure_len;
            }
            measure_start_index = i + 1;
            measure_len = 0;
        }
    }

    for(int i = 0; i < max_len; i++)
        cout << max_start_index + i << ' ';
    cout << endl;

    return max_len;
}
