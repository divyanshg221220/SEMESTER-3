// Interfaces
// Realize the diamond structure using the concept of multiple inheritance through interfaces.
interface EduMin {
    void nep();
}
interface UGC extends EduMin {
    void recognize();
}
interface AICTE extends EduMin {
    void acredit();
}
interface Uni extends UGC, AICTE {
    void uni();
}
class GGSIPU implements Uni {
    @Override 
    public void nep() {
        System.out.println("National Education Policy Provided by Education Ministry of India");
    }
    @Override
    public void recognize() {
        System.out.println("Recognized by University Grants Commission");
    }
    @Override
    public void acredit() {
        System.out.println("Accredited by All India Council for Technical Education");
    }
    @Override
    public void uni() {
        System.out.println("Guru Gobind Singh Indraprastha University");
    }
}
class InterfaceMain {
    public static void main(String[] args) {
        GGSIPU ggsipu = new GGSIPU();
        ggsipu.nep();
        ggsipu.recognize();
        ggsipu.acredit();
        ggsipu.uni();
    }
}