//Reader
//Writer
import java.io.*;
class Testchar{
	public static void main(String [] args){
		FileReader fr = null;
		FileWriter fw = null;
		try{
			fr = new FileReader("f:/coder/java/src/from.txt");
			fw = new FileWriter("f:/coder/java/src/to.txt");
			char [] buffer = new char[100];
			int len = fr.read(buffer, 0, buffer.length);
			fw.write(buffer, 0, len);
		}
		catch(Exception e){
			System.out.println(e);
		}
		finally{
			try{
				fr.close();
				fw.close();
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
	}
}