public class Fibonacci
{
  private static long fibonacci(int n)
  {
    if (n <= 0)
    {
      throw new IllegalArgumentException("You cannot get a nonpositive Fibonacci number.");
    }
    if (n <= 2)
    {
      return 1L;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
  }

  public static void main(String[] args)
  {
    if (args.length == 0)
    {
      System.err.println("You must enter a term number.");
      System.exit(1);
    }
    try
    {
      int n = Integer.parseInt(args[0]);
      System.out.println("The Fibonacci number " + n + " is " + fibonacci(n));
    }
    catch (NumberFormatException e)
    {
      System.err.println("You must enter a natural number as the first argument.");
      System.exit(2);
    }
    catch (IllegalArgumentException e)
    {
      System.err.println(e.getMessage());
      System.exit(3);
    }
  }
}
