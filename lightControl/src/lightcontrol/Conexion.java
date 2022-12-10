package lightcontrol;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conexion {
    
    Connection con;//Se declaran los elementos para iniciar la base de datos
    public static final String URL = "jdbc:mysql://localhost:3306/lightcontrol",
                               USERNAME = "root",
                               PASSWORD = "";

    public Conexion() {
        try{
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        }catch(ClassNotFoundException | SQLException e){
            System.out.println("Error: "+e);
        }
    }

    public Connection getConection() {
        return con;
    }
}