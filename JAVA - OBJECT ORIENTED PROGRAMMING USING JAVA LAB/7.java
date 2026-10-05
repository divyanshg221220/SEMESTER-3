// Interfaces
// Realize the diamond structure using the concept of multiple inheritance through interfaces.
interface EduMin {
    void edumin();
}
interface UGC extends EduMin {
    void ugc();
}
interface AICTE extends EduMin {
    void aicte();
}
interface Uni extends UGC, AICTE {
    void uni();
}
class GGSIPU implements Uni {
    @Override
    public void edumin() {
        System.out.println("Education Ministry of India");
    }
    @Override
    public void ugc() {
        System.out.println("University Grants Commission");
    }
    @Override
    public void aicte() {
        System.out.println("All India Council for Technical Education");
    }
    @Override
    public void uni() {
        System.out.println("Guru Gobind Singh Indraprastha University");
    }
}
class InterfaceMain {
    public static void main(String[] args) {
        GGSIPU ggsipu = new GGSIPU();
        ggsipu.edumin();
        ggsipu.ugc();
        ggsipu.aicte();
        ggsipu.uni();
    }
}