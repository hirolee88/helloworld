class Test01{
	public static void main(String[] args) {
		Plumber pl = new Plumber();
		AWorker apl = new AWorker(pl);
		apl.doSomeWork();
	}
}