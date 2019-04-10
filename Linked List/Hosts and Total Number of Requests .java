/**
 * n this challenge, write a program to analyze a log file and summarize the results. 
 * Given a text file of an http requests log, list the number of requests from each host Output should be 
 * directed to a file as described in the Program Description below The format of the log file, a text 
 * file with a txt extension, follows. Each line contains a single log record with the following columns 
 * (in order) 
 * 1. The hostname of the host making the request 
 * 2. This column's values are missing and were replaced by a hyphen. 
 * 3. This column's values are missing and were replaced by a hyphen. 
 * 4. A timestamp enclosed in square brackets following the format /DD/mmm/wYY.HH:MM.SS-0400], 
 * where DD is the day of the month, mmm is the name of the month, YYYY is the year, HH:MM SS 
 * is the time in 24-hour format, and-0400 is the time zone 
 * 5. The request, enclosed in quotes (e.g, "GET /images/NASA-logosmall.gif HTTP/1.0) 
 * 6. The HTTP response code.
 * 7. The total number of bytes sent in the response Example log file entry Function Description
 * 
 * Your function must create a unique list of hostnames with their number of requests and output to a
 * file named records filename where filename is replaced with the input filename. Each hostname should 
 * be followed by a space then the number of requests and a newline. Order doesn't matter
 * 
 * Constraints The log file has a maximum of 2 105 lines of records.
 */

import java.io.*;
import java.util.*;
import java.util.regex.*;


public class Solution {
    private static final Scanner scan = new Scanner(System.in);
    
    public static void main(String args[]) throws Exception {
        // File Specifications
        String filename;
        filename = scan.nextLine();
        File file = new File(filename);

        // Output Map
        Map<String, Integer> accessMap = new HashMap<>();

        // Read Specifications
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line;
        while ((line = br.readLine()) != null) {
            String currentUrl = line.split(" ")[0]; 
            Integer prevValue = accessMap.getOrDefault(currentUrl, 0);
            System.out.println(currentUrl + " " + prevValue);
            accessMap.put(currentUrl, prevValue+1);
        }
        BufferedWriter writer = new BufferedWriter(new FileWriter("records_"+filename));
        for(String key: accessMap.keySet()) {
            writer.write(key);
            writer.write(" ");
            writer.write(accessMap.getOrDefault(key, 0).toString());
            writer.write("\n");
            // System.out.println(key + " " + accessMap.get(key));
        }
        writer.close();
    }
}

