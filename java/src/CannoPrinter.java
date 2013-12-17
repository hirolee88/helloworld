class CannoPrinter implements Printer{

	public void print(String s){
		System.out.println("Canno printf-->" + s);
	}
	
	private void clean(){
		System.out.println("clean");
	}

	public void open(){
		System.out.println("Canno open");
	}

	public void close(){
		this.clean();
		System.out.println("Canno close");
	}
}