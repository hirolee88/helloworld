class USBPhone implements USB, WiFi{
	public void read(){
		System.out.println("read USB");
	}

	public void write(){
		System.out.println("write USB");
	}

	public void open(){
		System.out.println("open WiFi");
	}

	public void close(){
		System.out.println("close WiFi");
	}
}