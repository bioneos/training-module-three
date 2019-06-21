import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class SortingStrings
{
  private static String toString(List<String> strings)
  {
    StringBuilder stringBuilder = new StringBuilder();
    strings.forEach(string -> {
      stringBuilder.append(string);
      stringBuilder.append(" ");
    });
    return stringBuilder.toString();
  }

  private static void sort(List<String> strings)
  {
    strings.sort((first, second) -> {
      List<Character> firstCharacters = first.chars().mapToObj(ch -> (char) ch).sorted().collect(Collectors.toList());
      Collections.reverse(firstCharacters);
      List<Character> secondCharacters = second.chars().mapToObj(ch -> (char) ch).sorted().collect(Collectors.toList());
      Collections.reverse(secondCharacters);

      int minCharacters = Math.min(firstCharacters.size(), secondCharacters.size());
      for (int i = 0; i < minCharacters; i++)
      {
        char firstChar = (char) (firstCharacters.get(i) - 26);
        char secondChar = (char) (secondCharacters.get(i) - 26);
        if (firstChar - secondChar > 0)
        {
          return 1;
        }
        else if (secondChar - firstChar > 0)
        {
          return -1;
        }
      }
      if (firstCharacters.size() == secondCharacters.size())
      {
        return 0;
      }
      else if (secondCharacters.size() == minCharacters)
      {
        return 1;
      }
      else // if (firstCharacters.size() == minCharacters)
      {
        return -1;
      }
    });
  }

  public static void main(String[] args)
  {
    if (args.length == 0)
    {
      System.err.println("You must enter a term number.");
      System.exit(1);
    }

    try (BufferedReader bufferedReader = new BufferedReader(new FileReader(args[0])))
    {
      StringBuilder stringBuilder = new StringBuilder();
      String line = bufferedReader.readLine();
      while (line != null)
      {
        stringBuilder.append(line);
        stringBuilder.append(" ");
        line = bufferedReader.readLine();
      }
      String result = stringBuilder.toString();

      List<String> words = Arrays.asList(result.split(" "));
      System.out.println("Unsorted list: " + SortingStrings.toString(words));
      SortingStrings.sort(words);
      System.out.println("Sorted list: " + SortingStrings.toString(words));
    }
    catch (IOException e)
    {
      System.err.println(e.getMessage());
      System.exit(2);
    }
  }
}
