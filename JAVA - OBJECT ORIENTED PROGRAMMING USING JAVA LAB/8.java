// Demonstrate working of Runtime Polymorphism
interface Security {
    public void blockport();
    public void allowport();
    public void Httpssecurity();
    public void DNSsecurity();
    public void Mail();
}
class Firewall implements Security {
    public void intializedefaultFirewall() {
        System.out.println("Default firewall initialized");
    }
    @Override
    public void blockport() {
        System.out.println("Firewall blocking port");
    }
    @Override
    public void allowport() {
        System.out.println("Firewall allowing port");
    }
    @Override
    public void Httpssecurity() {
        System.out.println("Firewall: HTTPS security");
    }
    @Override
    public void DNSsecurity() {
        System.out.println("Firewall: DNS security");
    }
    @Override
    public void Mail() {
        System.out.println("Firewall: Mail security");
    }
}
class UTM extends Firewall {
    @Override
    public void blockport() {
        System.out.println("UTM blocking port");
    }
    @Override
    public void allowport() {
        System.out.println("UTM allowing port");
    }
    @Override
    public void Httpssecurity() {
        System.out.println("UTM: HTTPS security");
    }
    @Override
    public void DNSsecurity() {
        System.out.println("UTM: DNS security");
    }
    @Override
    public void Mail() {
        System.out.println("UTM: Mail security");
    }
}
class RuntimePolymorphismMain {
    public static void main(String[] args) {
        Security ref;
        Firewall object1 = new Firewall();
        UTM object2 = new UTM();
        object1.intializedefaultFirewall();
        ref = object1;
        ref.blockport();
        ref = object2;
        ref.blockport();
        ref.DNSsecurity();
        ref.Httpssecurity();
        ref.Mail();
    }
}