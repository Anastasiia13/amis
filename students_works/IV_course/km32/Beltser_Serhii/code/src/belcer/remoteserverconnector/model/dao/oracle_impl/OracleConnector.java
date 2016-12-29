package belcer.remoteserverconnector.model.dao.oracle_impl;

import belcer.remoteserverconnector.model.entity.ConnectionProfile;
import belcer.remoteserverconnector.model.entity.Role;
import belcer.remoteserverconnector.model.entity.User;

import javax.naming.NamingException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public enum OracleConnector {
  INSTANCE,;

  private final static String HOST = "localhost";
  private final static String PORT = "1521";
  private final static String SCHEMA = "xe";
  private final static String URL = "jdbc:oracle:thin:@%1$s:%2$s/%3$s";
  private final static String USER_LOGIN = "system";
  private final static String USER_PASS = "root";
  private Connection conn;

  private static final String usersTable = "users";
  private static final String connectionsTable = "connection_profile";
  private List<ConnectionProfile> allConnections;


  OracleConnector() {
    open();
  }

  public Connection open() {
    System.out.println("Oracle DB connection is open");
    try {
      if (conn != null && !conn.isClosed()) {
        conn.close();
      }
    } catch (SQLException e) {
      e.printStackTrace();
    }
    try {
      conn = createConnection();
    } catch (SQLException | ClassNotFoundException | NamingException e) {
      e.printStackTrace();
    }
    return conn;
  }

  public Connection createConnection() throws SQLException, ClassNotFoundException, NamingException {
    System.out.println("Oracle DB connection is created");
    DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
    return DriverManager.getConnection(String.format(URL, HOST, PORT, SCHEMA), USER_LOGIN, USER_PASS);
  }

  // Users
  public User getUser(String username) {
    conn = open();
    PreparedStatement ins = null;
    User user = null;
    try {
      ins = conn.prepareStatement("SELECT * FROM " + usersTable + " WHERE username = ?");
      ins.setString(1, username);
      ResultSet resultSet = ins.executeQuery();
      if (!resultSet.isBeforeFirst()) {
        return null;
      }
      resultSet.next();
      user = new User(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4),
          resultSet.getDate(5), Role.parseString(resultSet.getString(6)));
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
    return user;
  }

  public void saveUser(User user) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement(
          "INSERT INTO " + usersTable + " (username, email, password, registration_date, last_login_date, role) " +
              "VALUES (?, ?, ?, ?, ?, ?)");
      ins.setString(1, user.getUsername());
      ins.setString(2, user.getEmail());
      ins.setString(3, user.getPassword());
      ins.setDate(4, user.getRegistrationDate());
      ins.setDate(5, user.getLastLogin());
      ins.setString(6, user.getRole().toString());
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

  public void close() {
    try {
      if (conn != null && !conn.isClosed()) {
        conn.close();
      }
    } catch (SQLException e) {
      e.printStackTrace();
    }
    System.out.println("Connection is closed.");
  }

  public List<User> getAllUsers() {
    conn = open();
    PreparedStatement ins = null;
    User user = null;
    List<User> users = new ArrayList<User>();
    try {
      ins = conn.prepareStatement("SELECT * FROM " + usersTable);
      ResultSet resultSet = ins.executeQuery();
      if (!resultSet.isBeforeFirst()) {
        return null;
      }
      while (resultSet.next()) {
//        user = new User(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4), resultSet.getDate(5));
        users.add(new User(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4),
            resultSet.getDate(5), Role.parseString(resultSet.getString(6))));
      }
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
    return users;
  }

  public User updateUser(String username, User user) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement(
          "UPDATE " + usersTable + " " +
              " SET" +
              " username=?, " +
              " email=?, " +
              " password=?, " +
              " registration_date=?, " +
              " last_login_date=?, " +
              " role=? " +
              " WHERE username = ?"
      );
      ins.setString(1, user.getUsername());
      ins.setString(2, user.getEmail());
      ins.setString(3, user.getPassword());
      ins.setDate(4, user.getRegistrationDate());
      ins.setDate(5, user.getLastLogin());
      ins.setString(6, user.getRole().toString());
      ins.setString(7, username);
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
    return user;
  }

  // Connections
  public ConnectionProfile getConnection(String title, String username) {
    conn = open();
    PreparedStatement ins = null;
    ConnectionProfile connection = null;
    try {
      ins = conn.prepareStatement("SELECT title, connection_password, connection_user, port, host, protocol, " +
          " date_modified, last_connection_date, deleted, saved_by_user, username, created_date FROM connection_profile WHERE username_fk = ? AND title = ?");
      ins.setString(1, username);
      ins.setString(2, title);
      ResultSet resultSet = ins.executeQuery();
      if (!resultSet.isBeforeFirst()) {
        return null;
      }
      resultSet.next();
      connection = new ConnectionProfile(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getString(4),
          resultSet.getString(5), resultSet.getString(6), resultSet.getDate(7), resultSet.getDate(8), resultSet.getDate(9), resultSet.getBoolean(10),
          resultSet.getBoolean(11), resultSet.getString(12)
      );
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
    return connection;
  }

  public List<ConnectionProfile> getAllConnections() {
    conn = open();
    PreparedStatement ins = null;
    User user = null;
    List<ConnectionProfile> connections = new ArrayList<>();
    try {
      ins = conn.prepareStatement("SELECT * FROM \"connection_profile\"");
      ResultSet resultSet = ins.executeQuery();
      if (!resultSet.isBeforeFirst()) {
        return null;
      }
      while (resultSet.next()) {
//        user = new User(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4), resultSet.getDate(5));
        connections.add(new ConnectionProfile(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getString(4),
            resultSet.getString(5), resultSet.getString(6), resultSet.getDate(7), resultSet.getDate(8), resultSet.getDate(9), resultSet.getBoolean(10),
            resultSet.getBoolean(11), resultSet.getString(12)
        ));
      }
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
    return connections;
  }

  public void deleteConnection(String username, String title) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement("DELETE FROM connection_profile WHERE username=? AND title = ?");
      ins.setString(1, username);
      ins.setString(2, title);
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

  public void deleteUser(String username) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement("DELETE FROM users WHERE username=?");
      ins.setString(1, username);
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

  public void deleteConnectionProfile(String title, String username) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement("DELETE FROM \"connection_profile\" WHERE username=? AND title=?");
      ins.setString(1, username);
      ins.setString(2, title);
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

  public void saveConnection(ConnectionProfile connectionProfile) {
    conn = open();
    PreparedStatement ins = null;
    try {
      ins = conn.prepareStatement(
          "INSERT INTO \"connection_profile\" (\"title\", \"connection_password\", \"connection_user\", \"port\", \"host\", \"protocol\", " +
              "\"date_modified\", \"last_connection_date\", " +
              "\"deleted\", \"saved_by_user\", \"username\", \"created_date\") " +
              "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
      ins.setString(1, connectionProfile.getTitle());
      ins.setString(2, connectionProfile.getConnectionPass());
      ins.setString(3, connectionProfile.getConnectionUser());
      ins.setString(4, connectionProfile.getPort());
      ins.setString(5, connectionProfile.getHost());
      ins.setString(6, connectionProfile.getProtocol());
      ins.setDate(7, connectionProfile.getDateModified());
      ins.setDate(8, connectionProfile.getLastConnectionDate());
      ins.setBoolean(9, connectionProfile.isDeleted());
      ins.setBoolean(10, connectionProfile.isSavedByUser());
      ins.setString(11, connectionProfile.getUsername());
      ins.setDate(12, connectionProfile.getDateCreated());
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

  public void updateConnection(ConnectionProfile connectionProfile) {
    conn = open();
    PreparedStatement ins = null;
    try {
//      "title", "connection_password", "connection_user", "port", "host", "protocol", " +
//      "\"date_modified\", \"last_connection_date\", " +
//          ""deleted", "saved_by_user", "username_fk", "created_date"
      ins = conn.prepareStatement(
          "UPDATE \"connection_profile\" " +
              " SET" +
              " title=?, " +
              " connection_password=?, " +
              " connection_user=?, " +
              " port=?, " +
              " host=?, " +
              " protocol=?, " +
              " date_modified=?, " +
              " last_connection_date=?, " +
              " deleted=?, " +
              " saved_by_user=?, " +
              " username=?, " +
              " created_date=? " +
              " WHERE username = ? AND title = ?"
      );
      ins.setString(1, connectionProfile.getTitle());
      ins.setString(2, connectionProfile.getConnectionPass());
      ins.setString(3, connectionProfile.getConnectionUser());
      ins.setString(4, connectionProfile.getPort());
      ins.setString(5, connectionProfile.getHost());
      ins.setString(6, connectionProfile.getProtocol());
      ins.setDate(7, connectionProfile.getDateModified());
      ins.setDate(8, connectionProfile.getLastConnectionDate());
      ins.setBoolean(9, connectionProfile.isDeleted());
      ins.setBoolean(10, connectionProfile.isSavedByUser());
      ins.setString(11, connectionProfile.getUsername());
      ins.setDate(12, connectionProfile.getDateCreated());
      ins.setString(13, connectionProfile.getUsername());
      ins.setString(14, connectionProfile.getTitle());
      ins.executeQuery();
    } catch (SQLException e) {
      e.printStackTrace();
    } finally {
      close();
    }
  }

//  public UserDAO getUserDAO() {
//
//    // CloudscapeCustomerDAO implements CustomerDAO
//    return new OracleUserDAO();
//  }
//  public PaymentDAO getPaymentDAO() {
//    // CloudscapeAccountDAO implements AccountDAO
//    return new OraclePaymentDAO();
//  }
//  public CardDAO getCardDAO() {
//    // CloudscapeOrderDAO implements OrderDAO
//    return new OracleCardDAO();
//  }


}