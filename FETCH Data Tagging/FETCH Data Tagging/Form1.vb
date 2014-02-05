Imports System.Text
Imports System.Net
Imports System.IO
Imports System.Data.SqlServerCe
Imports System.Data.SqlClient


Public Class Form1

    Private Sub Sample_DatatableBindingNavigatorSaveItem_Click(sender As Object, e As EventArgs) Handles SampleDatatableBindingNavigatorSaveItem.Click

        'validates latitude and longitude
        Dim longcheck = Val(LongitudeTextBox.Text)
        Dim latcheck = Val(LatitudeTextBox.Text)
        LatitudeTextBox.Text = latcheck
        LongitudeTextBox.Text = longcheck


        If DateTextBox.Text = "" Then
            MessageBox.Show("Error, no date specified!", "Error")
        ElseIf SpeciesTextBox.Text = "" Then
            MessageBox.Show("Error, no species specified!", "Error")
        ElseIf LongitudeTextBox.Text = "" Then
            MessageBox.Show("Error, no longitude specified!", "Error")
        ElseIf LatitudeTextBox.Text = "" Then
            MessageBox.Show("Error, no latitude specified!", "Error")
        ElseIf DateTextBox.Text(4) <> "/" Or DateTextBox.Text(7) <> "/" Then
            MessageBox.Show("Error, invalid date entered!", "Error")
        ElseIf NotesTextBox.Text = "" Then
            MessageBox.Show("Please put a unique note for identification!", "Error")
        Else


            Dim savecomm = New StringBuilder()
            savecomm.Append("INSERT INTO SampleDatatable (Date, Species, Longitude, Latitude, Notes, Sync) ")
            savecomm.Append("VALUES ('")
            savecomm.Append(DateTextBox.Text.ToString)
            savecomm.Append("','")
            savecomm.Append(SpeciesTextBox.Text.ToString)
            savecomm.Append("','")
            savecomm.Append(LongitudeTextBox.Text.ToString)
            savecomm.Append("','")
            savecomm.Append(LatitudeTextBox.Text.ToString)
            savecomm.Append("','")
            savecomm.Append(NotesTextBox.Text.ToString)
            savecomm.Append("','no')")

            Dim saveconnectionstring As String = ("Data Source=|DataDirectory|\Database\SampleDatabase.sdf")
            Dim saveconnection As New SqlCeConnection(saveconnectionstring)
            Dim savecmd = New SqlCeCommand(savecomm.ToString(), saveconnection)
            Try
                saveconnection.Open()
                Dim dr = savecmd.ExecuteNonQuery
                savecmd.Dispose()
                saveconnection.Close()
            Catch sqle As SqlException
                ' Do some logging or something. 
                MessageBox.Show("There was an error accessing your data. DETAIL: " & e.ToString())
            End Try

        End If


    End Sub

    Private Sub Clear_Click(sender As Object, e As EventArgs) Handles Clear.Click
        SpeciesTextBox.Text = ""
        DateTextBox.Text = ""
        NotesTextBox.Text = ""
        LongitudeTextBox.Text = ""
        LatitudeTextBox.Text = ""
    End Sub

    Private Sub Sync_Click(sender As Object, e As EventArgs) Handles Sync.Click

        'post request variables
        Dim request As HttpWebRequest
        Dim response As HttpWebResponse = Nothing
        Dim reader As StreamReader
        Dim address As Uri
        Dim data As StringBuilder
        Dim byteData() As Byte
        Dim postStream As Stream = Nothing

        'for post request loop
        Dim x As Integer = 0
        Dim element As String

        'easy way to get string values
        Dim species As String = SpeciesTextBox.Text
        Dim notes As String = NotesTextBox.Text
        Dim latitude As String = LatitudeTextBox.Text
        Dim longitude As String = LongitudeTextBox.Text
        Dim day As String = DateTextBox.Text

        'Gets all non-sync'd data
        Dim speciesList = Me.getList("species")
        Dim notesList = Me.getList("notes")
        Dim latitList = Me.getList("latitude")
        Dim longitList = Me.getList("longitude")
        Dim dayList = Me.getList("date")

        'Once all non-sync'd data has been gotten, sets value of everything to sync
        Dim comm = New StringBuilder()
        comm.Append("UPDATE SampleDatatable SET sync='yes'")

        Dim connectionstring As String = ("Data Source=|DataDirectory|\Database\SampleDatabase.sdf")
        Dim connection As New SqlCeConnection(connectionstring)
        Dim cmd = New SqlCeCommand(comm.ToString(), connection)
        Try
            connection.Open()
            Dim dr = cmd.ExecuteNonQuery
            cmd.Dispose()
            connection.Close()
        Catch sqle As SqlException
            ' Do some logging or something. 
            MessageBox.Show("There was an error accessing your data. DETAIL: " & e.ToString())
        End Try



        'Set the REST API URL
        address = New Uri("http://uifetch.herokuapp.com/samples")
        ' Create the web request

        'post request loop
        For Each element In speciesList
            request = DirectCast(WebRequest.Create(address), HttpWebRequest)

            ' Set type to POST  
            request.Method = "POST"
            request.ContentType = "application/x-www-form-urlencoded"


            ' Create the data we want to send (each data.Append is for specific paramater data) 
            data = New StringBuilder()
            data.Append("{""species"":""" + speciesList(x))
            data.Append(""",""notes"":""" + notesList(x))
            data.Append(""",""latitude"":""" + latitList(x))
            data.Append(""",""longitude"":""" + longitList(x))
            data.Append(""",""date_collected"":""" + dayList(x))
            data.Append("""}")
            x = x + 1

            ' Create a byte array of the data we want to send  
            byteData = UTF8Encoding.UTF8.GetBytes(data.ToString())
            '' Set the content length in the request headers  
            request.ContentLength = byteData.Length

            ' Write data  
            Try
                postStream = request.GetRequestStream()
                postStream.Write(byteData, 0, byteData.Length)
            Finally
                If Not postStream Is Nothing Then postStream.Close()
            End Try

            Try
                ' Get response  
                response = DirectCast(request.GetResponse(), HttpWebResponse)
                ' Get the response stream into a reader  
                reader = New StreamReader(response.GetResponseStream())
            Catch
                ' Update form textbox in threadsafe manner that posting to API failed
                MessageBox.Show("Error contacting server.", "Error!")
            Finally
                If Not response Is Nothing Then response.Close()
            End Try

        Next
    End Sub

    Public Function getList(column As String) As List(Of String)

        'grabs only non-sync'd items
        Dim comm = New StringBuilder()
        comm.Append("SELECT ")
        comm.Append(column)
        comm.Append(" FROM SampleDatatable WHERE sync<>'yes'")
        Dim x As Integer = 0

        Dim output As New List(Of String)()
        Dim connectionstring As String = ("Data Source=|DataDirectory|\Database\SampleDatabase.sdf")
        Dim connection As New SqlCeConnection(connectionstring)
        Dim cmd = New SqlCeCommand(comm.ToString(), connection)
        connection.Open()
        Try
            Dim dr = cmd.ExecuteReader()
            While dr.Read()
                output.Add(dr(column))
                x = x + 1
            End While

            dr.Close()
            cmd.Dispose()
            connection.Close()
        Catch e As SqlException
            ' Do some logging or something. 
            MessageBox.Show("There was an error accessing your data. DETAIL: " & e.ToString())
        End Try

        Return output

    End Function

    Private Sub BindingNavigatorDeleteItem_Click(sender As Object, e As EventArgs) Handles BindingNavigatorDeleteItem.Click

        Dim longcheck = Val(LongitudeTextBox.Text)
        Dim latcheck = Val(LatitudeTextBox.Text)
        LatitudeTextBox.Text = latcheck
        LongitudeTextBox.Text = longcheck

        Dim comm = New StringBuilder()
        comm.Append("DELETE FROM SampleDatatable WHERE Notes='")
        comm.Append(NotesTextBox.Text.ToString)
        comm.Append("' AND Longitude='")
        comm.Append(LongitudeTextBox.Text.ToString)
        comm.Append("' AND Latitude='")
        comm.Append(LatitudeTextBox.Text.ToString)
        comm.Append("' AND Species='")
        comm.Append(SpeciesTextBox.Text.ToString)
        comm.Append("'")

        Dim connectionstring As String = ("Data Source=|DataDirectory|\Database\SampleDatabase.sdf")
        Dim connection As New SqlCeConnection(connectionstring)
        Dim cmd = New SqlCeCommand(comm.ToString(), connection)
        connection.Open()
        cmd.ExecuteNonQuery()
        cmd.Dispose()
        connection.Close()

    End Sub
End Class
