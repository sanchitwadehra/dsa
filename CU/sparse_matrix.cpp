#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rows, columns;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> row_indices, column_indices, values;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] != 0)
            {
                row_indices.push_back(i);
                column_indices.push_back(j);
                values.push_back(matrix[i][j]);
            }
        }
    }

    cout << "Rows Order Vise:" << endl;
    for (int val : row_indices)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Columns Order Vise:" << endl;
    for (int val : column_indices)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Values Order Vise:" << endl;
    for (int val : values)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
