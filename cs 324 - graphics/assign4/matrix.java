

public class matrix
{
    
    double matrix[][] = new double[4][4];
    //init matrix to 0
    
    public matrix()
    {
     
	for (int i = 0; i < 4; i++)
	{
	    for ( int j = 0; j < 4; j++)
	    {
		matrix[i][j] = 0;
	    }
	}
    

    }

    public void SetMVal(int height, int width, double val)
    {
	matrix[height][width] = val;
    }

    public double GetMVal(int height, int width)
    {     
	return matrix[height][width];
    }

    public static matrix MultiplyM(double transVal, matrix A, matrix B)
    {
	matrix C = new matrix();

	for( int i = 0; i < 1; i++ )
	{
	    for( int j = 0; j < 4; j++ )
	    	{
	    		for( int x = 0; x < 4; x++ )
	    		{
		    C.matrix[i][x] += A.matrix[i][x] * B.matrix[x][j];
	    		}
	    	}	
	}

		return C;
    }

}