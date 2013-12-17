import java.util.*;
class Test{
	public static void main(String args[]){
		User u = new User("zhangsan", 12);
		HashMap<User, String> map = new HashMap<User, String>();
		map.put(u, "abc");

		String s = map.get(new User("zhangsan", 12));
		System.out.println(s);
		System.out.println(u);
	}
}
