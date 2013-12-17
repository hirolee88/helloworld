class HPPrinter implements Printer{
	public void print(String s){
		System.out.println("HP     printf-->" + s);
	}

	public void open(){
		System.out.println("HP open");
	}

	public void close(){
		System.out.println("HP close");
	}
}