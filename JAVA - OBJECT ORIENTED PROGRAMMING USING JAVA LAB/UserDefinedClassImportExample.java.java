import demo.example.PackageExample;

public class UserDefinedClassImportExample
{

	public static void main(String args[])
	{
		PackageExample objPackageExample = new PackageExample();
		objPackageExample.PublicMemberFunction();
		/* All the below functions are not accesible outside package */
		//objPackageExample.ProtectedMemberFunction();
		//objPackageExample.DefaultMemberFunction();
		//objPackageExample.PrivateMemberFunction();
	}
}