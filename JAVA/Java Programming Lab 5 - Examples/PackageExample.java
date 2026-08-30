package demo.example;

public class PackageExample
{

	/* Data members */
	int intMemberVar; //Default access modifier
	protected String stringMemberVar; //Protected access modifier
	private float floatMemberVar; //private access modifier
	public char charMemberVar; //public access modifier

	/* Member functions */
	public void PublicMemberFunction()
	{
		System.out.println("Public Member Function");
	}
	private void PrivateMemberFunction()
	{
		System.out.println("Private Member Function");
	}
	protected void ProtectedMemberFunction()
	{
		System.out.println("Protected Member Function");
	}
	void DefaultMemberFunction()
	{
		System.out.println("Default Member Function");
	}
	public static void main(String args[])
	{
		PackageExample objPackageExample = new PackageExample();
		objPackageExample.PublicMemberFunction();
		objPackageExample.ProtectedMemberFunction();
		objPackageExample.DefaultMemberFunction();
		objPackageExample.PrivateMemberFunction();
	}

}