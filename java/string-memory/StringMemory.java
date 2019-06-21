import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class StringMemory
{
  public static void main(String[] args)
  {
    if (args.length == 0)
    {
      System.err.println("You must enter a file name.");
      System.exit(1);
    }

    try (BufferedReader bufferedReader = new BufferedReader(new FileReader(args[0])))
    {
      StringBuilder stringBuilder = new StringBuilder();
      String line = bufferedReader.readLine();
      while (line != null)
      {
        stringBuilder.append(line);
        stringBuilder.append("\n");
        line = bufferedReader.readLine();
      }
      String[] results = stringBuilder.toString().split("\n");
      List<String> words1 = new ArrayList<>();
      words1.addAll(Arrays.asList(results[0].split(" ")));
      List<String> words2 = new ArrayList<>();
      words2.addAll(Arrays.asList(results[1].split(" ")));

      outer:
      for (int i = 0; i < words1.size(); i++)
      {
        String word1 = words1.get(i);
        for (int j = 0; j < words2.size(); j++)
        {
          if (word1 == words2.get(j))
          {
            words1.remove(i);
            words2.remove(i);
            i--;
            continue outer;
          }
        }
      }

      if (words1.isEmpty() && words2.isEmpty())
      {
        System.out.println("The lists will match!");
      }
      else
      {
        System.out.println("The lists won't match.");
      }
    }
    catch (IOException e)
    {
      System.err.println(e.getMessage());
      System.exit(2);
    }
  }
}
