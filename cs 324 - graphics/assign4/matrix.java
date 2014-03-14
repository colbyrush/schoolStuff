public class matrix
{
    
    double matrix[][] = new double[4][4];
    //init matrix to 0
    
    public matrix()
    {
   
	}


    public void setIdent()
    {
    	this.SetMVal(0,0,1);
    	this.SetMVal(0,1,0);
    	this.SetMVal(0,2,0);
    	this.SetMVal(0,3,0);
    	this.SetMVal(1,0,0);
    	this.SetMVal(1,1,1);
    	this.SetMVal(1,2,0);
    	this.SetMVal(1,3,0);
    	this.SetMVal(2,0,0);
    	this.SetMVal(2,1,0);
    	this.SetMVal(2,2,1);
    	this.SetMVal(2,3,0);
    	this.SetMVal(3,0,0);
    	this.SetMVal(3,1,0);
    	this.SetMVal(3,2,0);
    	this.SetMVal(3,3,1);
    }
    
    public void SetMVal(int height, int width, double val)
    {
	this.matrix[height][width] = val;
    }

    public double GetMVal(int height, int width)
    {     
	return this.matrix[height][width];
    }

}