int isUnique(int **matrix, int rows, int columns, int row, int column)
{
    int isUnique = 0;
    if (row == 0)
    {
        if (column == 0)
        {
            if (matrix[row][column + 1] == '*' && matrix[row + 1][column] == '*' && matrix[row + 1][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*' && matrix[row][column + 1] == '*' &&
                matrix[row + 1][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column == columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }
    }
    else if (row == rows - 1)
    {
        if (column == 0)
        {
            if (matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' && matrix[row][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column == columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }
    }
    else
    {
        if (column == 0)
        {
            if (matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*' && matrix[row + 1][column + 1] == '*' && matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*' && matrix[row + 1][column + 1] == '*' &&
                matrix[row + 1][column] == '*' && matrix[row + 1][column - 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column == columns - 1)
        {

            if (matrix[row - 1][column] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }
    }

    return isUnique;
}