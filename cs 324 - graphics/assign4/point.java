
public class point
{
    double x;
    double y;
    double z;

    public point ()
    {
	x = y = z = 0;
    }

    public void clearp()
    {
	x = 0.0;
	y = 0.0;
	z = 0.0;
    }

    public void SetX (double val)
    {
	x = val;
    }

    public double GetX()
    {
	return x;
    }

    public void SetY(double val)
    {
	y = val;
    }

    public double GetY()
    {
	return y;
    }

    public void SetZ(double val)
    {
	z = val;
    }

    public double GetZ()
    {
	return z;
    }
}