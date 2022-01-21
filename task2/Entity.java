public class Entity
{
    private String id;
    private String name;
    private String surname;
    private String occupation;
    private String gender;

    // getters and setters
    public void setId(String id)
    {
        this.id = id;
    }

    public String getId()
    {
        return id;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return name;
    }

    public void setSurname(String surname)
    {
        this.surname = surname;
    }

    public String getSurname()
    {
        return surname;
    }

    public String getFullName()
    {
        return name + ", " + surname + ".";
    }

    public void setOccupation(String occupation)
    {
        this.occupation = occupation;
    }

    public String getOccupation()
    {
        return occupation;
    }

    public void setGender(String gender)
    {
        this.gender = gender;
    }

    public String getGender()
    {
        return gender;
    }

    // initialise constructor ...
    public Entity(String id, String name, String surname, String occupation, String gender)
    {
        setId(id);
        setName(name);
        setSurname(surname);
        setOccupation(occupation);
        setGender(gender);
    }

    public void viewEntityDetails()
    {
        System.out.println("Full Name :" + getFullName());
        System.out.println("ID Number :" + getId());
        System.out.println("Sex :" + getGender());
        System.out.println("Occupation :" + getOccupation());
    }
}