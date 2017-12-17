import java.sql.*;

public class Test_Data_Base {	//Main Class
	private String pswd = null;
	private String usrName = null;
	
	private String sql = null;
	
	private Connection connection = null;
	private Statement stmt = null;
	private ResultSet resultset = null; 
	private PreparedStatement pstmt = null;

	private String dbDriver = "com.mysql.jdbc.Driver";
	private String gtcon = "jdbc:mysql://localhost/";
	
	Test_Data_Base() {	//Constructor, store username & password
	    usrName = "root";
	    pswd = "cy610610";
	    try {
	    	Class.forName(dbDriver);
	    } catch (ClassNotFoundException e) {
	    	e.printStackTrace();
	    }
	}

	public void Connect_to_DataBase(String dbName) { // Get Connect with DataBase
	    gtcon += dbName;
	    try {
		connection = DriverManager.getConnection(gtcon, this.usrName, this.pswd);
		stmt = connection.createStatement();
	    } catch(SQLException e) {
		System.out.println("Connection Error!");
	    }
	}

	public void ShowTable(String tab) {		// Show Table whose name is tab
	    sql = "SELECT * FROM " + tab;
	    try {
		resultset = stmt.executeQuery(sql);
		ResultSetMetaData data = resultset.getMetaData();
		String title = "";
		for(int i = 1; i <= data.getColumnCount(); i++) {
		    title += data.getColumnName(i);
		    if(i != data.getColumnCount()) title += "\t\t";
		}
		System.out.println(title);
		while(resultset.next()) {
		    Student stu = new Student(resultset.getString(1), resultset.getString(2),
			    resultset.getString(3), resultset.getDate(4),
			    resultset.getString(5), resultset.getInt(6));
		    stu.Getter();
		}
	    } catch(SQLException e) {
		System.out.println("ShowTable Synax Error!");
	    }
	} 

	public void InsertStudent(Student stu) {	// Insert a new student into Student Table
	    sql = "INSERT INTO Student(SNo, SName, Sex, BirthDay, ClassNo, Age) VALUES(?,?,?,?,?,?)";
	    /*
	    sql = sql + (stu.GetStudentNo() + ", " + stu.GetStudentName() + ", " + 
		    stu.GetStudentSex() + ", " + stu.GetStudentBirthDay() + ", " +
		    stu.GetStudentClassNo() + ", " + stu.GetStudentAge()) + ")";
	    */
	    if(InsertStudentByP(stu, sql)) {
		System.out.println("Successfuly Insert!");
	    }
	    else {
		System.out.println("Insert Synax Error!");
	    }
	}

	private boolean InsertStudentByP(Student stu, String inssql) { // Insert student by PrepareStatement
	    try {
		pstmt = connection.prepareStatement(inssql);
		//System.out.println("PrepareStatement Done!");
		
		pstmt.setString(1, stu.GetStudentNo());
		pstmt.setString(2, stu.GetStudentName());
		pstmt.setString(3, stu.GetStudentSex());
		pstmt.setDate(4, stu.GetStudentBirthDay());
		pstmt.setString(5, stu.GetStudentClassNo());
		pstmt.setInt(6, stu.GetStudentAge());

		//System.out.println("PrepareStatement Set Value Done!");
		pstmt.executeUpdate();

	    } catch(SQLException e) {
		return false;
	    }
	    return true;
	}

	public void Serach(String searchsql) {			    //Searching By searchsql
	    try {

		resultset = stmt.executeQuery(searchsql);

	        while(resultset.next()) {
			System.out.println(resultset.getString("SNo") + "\t" + resultset.getString("SName"));
		}
	     } catch(Exception e) {
		 System.out.println("Search Error!");
	     }
	}

	public void disConnection() {				    //Get disconnection with Database
	    try {
		/* Dis Connection */
	    } catch(Exception e) {
		System.out.println("Disconnection Error!");
		return ;
	    }
	    System.out.println("Successfuly disconnected!");
	}

	public void Manipulate() {				    //Delete Student Record
	    sql = "DELETE FROM Student WHERE SName = 'Triose'";
	    System.out.println(sql);
	}
	
	public static void main (String [] args) {
	    Test_Data_Base tdb = new Test_Data_Base();
	    try {
		tdb.Connect_to_DataBase("EDUCATION");//Get Connect with DataBase
		tdb.ShowTable("Student");	     //Display Student Table
		tdb.InsertStudent(new Student("Triose", "1001", "MALE", new Date(19950105), "00706", 21));
		//Insert new Student
		tdb.ShowTable("Student");	    //Display Student Table
		String searchsql = "SELECT SNo,SName FROM Student " //Searching synatx
		     + "WHERE (SNo IN (SELECT SNo FROM Score GROUP BY SNo HAVING COUNT(CNo) > 1))";
		tdb.Serach("SELECT SNo,SName FROM Student WHERE " + //Searching method
			"(SNo IN (SELECT SNo FROM Score GROUP BY SNo HAVING COUNT(CNo) > 1))");
		tdb.Manipulate();				    //Delete new Student
		tdb.ShowTable("Student");			    //Display Student Table
	    } catch(Exception e) {
		System.out.println("Main mathod Error!");
	    } finally {
		tdb.disConnection();
	    }
	}
}

/* Student */
class Student {
    private String name = null;
    private String no = null;
    private String sex = null;
    private Date birthday = null;
    private String classno;
    private int age;

    /* Interfaces */
    Student(String sn_, String no_, String sex_, Date btd_, String clno_, int age_) {
	if(sn_ != null) name = sn_;
	if(no_ != null) no = no_;
	if(sex_ != null) sex = sex;
	if(btd_ != null) birthday = btd_;
	if(clno_ != null) classno = clno_;
	age = age_;
    }

    void Setter(String sn_, String no_, String sex_, Date btd_, String clno_, int age_) {
	if(sn_ != null) name = sn_;
	if(no_ != null) no = no_;
	if(sex_ != null) sex = sex_;
	if(btd_ != null) birthday = btd_;
	if(clno_ != null) classno = clno_;
	age = age_;
    }
    
    void Getter() {
	System.out.println(name + "\t\t" + no + "\t\t" + sex + "\t\t"
		+ birthday + "\t\t" + classno + "\t\t" + age);
    }

    void SetStudentName(String name_) {
	this.name = name_;
    }
    String GetStudentName() {
	return name;
    }
    void SetStudentSex(String sex_) {
	this.sex = sex_;
    }
    String GetStudentSex() {
	return sex;
    }
    void SetStudentNo(String no_) {
	this.no = no_;
    }
    String GetStudentNo() {
	return no;
    }
    void SetStudentBirthDat(Date btd_) {
	this.birthday = btd_;
    }
    Date GetStudentBirthDay() {
	return birthday;
    }
    void SetStudentClassNo(String cno_) {
	this.classno = cno_;
    }
    String GetStudentClassNo() {
	return classno;
    }
    void SetStudentAge(int age_) {
	this.age = age_;
    }
    int GetStudentAge() {
	return this.age;
    }
}
