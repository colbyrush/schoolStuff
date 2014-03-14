public class viewport 
{
    public double x1, y1, x2, y2;
 
    
    public viewport(double a, double b, double c, double d)
    {
        this.x1 = a;
        this.y1 = b;
        this.x2 = c;
        this.y2 = d;
    }
    
    public void DefineViewport(double a, double b, double c, double d)
    {
        this.x1 = a;
        this.y1 = b;
        this.x2 = c;
        this.y2 = d;
    }    
}