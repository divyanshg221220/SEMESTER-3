// Demonstrate working of Runtime Polymorphism
interface Security {
    public void blockport();
    public void allowport();
}
class Firewall implements Security {
    @Override
    public void blockport() {
        System.out.println("Firewall blocking port");
    }
    @Override
    public void allowport() {
        System.out.println("Firewall allowing port");
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
}
class RuntimePolymorphismMain {
    public static void main(String[] args) {
        Security ref;
        Firewall object1 = new Firewall();
        UTM object2 = new UTM();
        ref = object1;
        ref.blockport();
        ref = object2;
        ref.blockport();
    }
}