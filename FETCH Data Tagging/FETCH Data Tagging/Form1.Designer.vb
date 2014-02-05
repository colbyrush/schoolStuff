<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim DateLabel As System.Windows.Forms.Label
        Dim SpeciesLabel As System.Windows.Forms.Label
        Dim LongitudeLabel As System.Windows.Forms.Label
        Dim LatitudeLabel As System.Windows.Forms.Label
        Dim NotesLabel As System.Windows.Forms.Label
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Clear = New System.Windows.Forms.Button()
        Me.Sync = New System.Windows.Forms.Button()
        Me.SampleDatabaseDataSet = New FETCH_Data_Tagging.SampleDatabaseDataSet()
        Me.SampleDatatableBindingSource = New System.Windows.Forms.BindingSource(Me.components)
        Me.SampleDatatableTableAdapter = New FETCH_Data_Tagging.SampleDatabaseDataSetTableAdapters.SampleDatatableTableAdapter()
        Me.TableAdapterManager = New FETCH_Data_Tagging.SampleDatabaseDataSetTableAdapters.TableAdapterManager()
        Me.SampleDatatableBindingNavigator = New System.Windows.Forms.BindingNavigator(Me.components)
        Me.BindingNavigatorAddNewItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorCountItem = New System.Windows.Forms.ToolStripLabel()
        Me.BindingNavigatorDeleteItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorMoveFirstItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorMovePreviousItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorSeparator = New System.Windows.Forms.ToolStripSeparator()
        Me.BindingNavigatorPositionItem = New System.Windows.Forms.ToolStripTextBox()
        Me.BindingNavigatorSeparator1 = New System.Windows.Forms.ToolStripSeparator()
        Me.BindingNavigatorMoveNextItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorMoveLastItem = New System.Windows.Forms.ToolStripButton()
        Me.BindingNavigatorSeparator2 = New System.Windows.Forms.ToolStripSeparator()
        Me.SampleDatatableBindingNavigatorSaveItem = New System.Windows.Forms.ToolStripButton()
        Me.DateTextBox = New System.Windows.Forms.TextBox()
        Me.SpeciesTextBox = New System.Windows.Forms.TextBox()
        Me.LongitudeTextBox = New System.Windows.Forms.TextBox()
        Me.LatitudeTextBox = New System.Windows.Forms.TextBox()
        Me.NotesTextBox = New System.Windows.Forms.TextBox()
        DateLabel = New System.Windows.Forms.Label()
        SpeciesLabel = New System.Windows.Forms.Label()
        LongitudeLabel = New System.Windows.Forms.Label()
        LatitudeLabel = New System.Windows.Forms.Label()
        NotesLabel = New System.Windows.Forms.Label()
        CType(Me.SampleDatabaseDataSet, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.SampleDatatableBindingSource, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.SampleDatatableBindingNavigator, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SampleDatatableBindingNavigator.SuspendLayout()
        Me.SuspendLayout()
        '
        'DateLabel
        '
        DateLabel.AutoSize = True
        DateLabel.Location = New System.Drawing.Point(12, 25)
        DateLabel.Name = "DateLabel"
        DateLabel.Size = New System.Drawing.Size(114, 13)
        DateLabel.TabIndex = 3
        DateLabel.Text = "Date (YYYY/MM/DD):"
        '
        'SpeciesLabel
        '
        SpeciesLabel.AutoSize = True
        SpeciesLabel.Location = New System.Drawing.Point(12, 48)
        SpeciesLabel.Name = "SpeciesLabel"
        SpeciesLabel.Size = New System.Drawing.Size(48, 13)
        SpeciesLabel.TabIndex = 5
        SpeciesLabel.Text = "Species:"
        '
        'LongitudeLabel
        '
        LongitudeLabel.AutoSize = True
        LongitudeLabel.Location = New System.Drawing.Point(12, 74)
        LongitudeLabel.Name = "LongitudeLabel"
        LongitudeLabel.Size = New System.Drawing.Size(57, 13)
        LongitudeLabel.TabIndex = 7
        LongitudeLabel.Text = "Longitude:"
        '
        'LatitudeLabel
        '
        LatitudeLabel.AutoSize = True
        LatitudeLabel.Location = New System.Drawing.Point(12, 97)
        LatitudeLabel.Name = "LatitudeLabel"
        LatitudeLabel.Size = New System.Drawing.Size(48, 13)
        LatitudeLabel.TabIndex = 9
        LatitudeLabel.Text = "Latitude:"
        '
        'NotesLabel
        '
        NotesLabel.AutoSize = True
        NotesLabel.Location = New System.Drawing.Point(12, 119)
        NotesLabel.Name = "NotesLabel"
        NotesLabel.Size = New System.Drawing.Size(87, 13)
        NotesLabel.TabIndex = 11
        NotesLabel.Text = "Additional Notes:"
        '
        'Clear
        '
        Me.Clear.Location = New System.Drawing.Point(15, 177)
        Me.Clear.Name = "Clear"
        Me.Clear.Size = New System.Drawing.Size(75, 23)
        Me.Clear.TabIndex = 0
        Me.Clear.Text = "Clear"
        Me.Clear.UseVisualStyleBackColor = True
        '
        'Sync
        '
        Me.Sync.Location = New System.Drawing.Point(15, 139)
        Me.Sync.Name = "Sync"
        Me.Sync.Size = New System.Drawing.Size(75, 23)
        Me.Sync.TabIndex = 1
        Me.Sync.Text = "Sync"
        Me.Sync.UseVisualStyleBackColor = True
        '
        'SampleDatabaseDataSet
        '
        Me.SampleDatabaseDataSet.DataSetName = "SampleDatabaseDataSet"
        Me.SampleDatabaseDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema
        '
        'SampleDatatableBindingSource
        '
        Me.SampleDatatableBindingSource.DataMember = "SampleDatatable"
        Me.SampleDatatableBindingSource.DataSource = Me.SampleDatabaseDataSet
        '
        'SampleDatatableTableAdapter
        '
        Me.SampleDatatableTableAdapter.ClearBeforeFill = True
        '
        'TableAdapterManager
        '
        Me.TableAdapterManager.BackupDataSetBeforeUpdate = False
        Me.TableAdapterManager.SampleDatatableTableAdapter = Me.SampleDatatableTableAdapter
        Me.TableAdapterManager.UpdateOrder = FETCH_Data_Tagging.SampleDatabaseDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete
        '
        'SampleDatatableBindingNavigator
        '
        Me.SampleDatatableBindingNavigator.AddNewItem = Me.BindingNavigatorAddNewItem
        Me.SampleDatatableBindingNavigator.BindingSource = Me.SampleDatatableBindingSource
        Me.SampleDatatableBindingNavigator.CountItem = Me.BindingNavigatorCountItem
        Me.SampleDatatableBindingNavigator.DeleteItem = Me.BindingNavigatorDeleteItem
        Me.SampleDatatableBindingNavigator.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.BindingNavigatorMoveFirstItem, Me.BindingNavigatorMovePreviousItem, Me.BindingNavigatorSeparator, Me.BindingNavigatorPositionItem, Me.BindingNavigatorCountItem, Me.BindingNavigatorSeparator1, Me.BindingNavigatorMoveNextItem, Me.BindingNavigatorMoveLastItem, Me.BindingNavigatorSeparator2, Me.BindingNavigatorAddNewItem, Me.BindingNavigatorDeleteItem, Me.SampleDatatableBindingNavigatorSaveItem})
        Me.SampleDatatableBindingNavigator.Location = New System.Drawing.Point(0, 0)
        Me.SampleDatatableBindingNavigator.MoveFirstItem = Me.BindingNavigatorMoveFirstItem
        Me.SampleDatatableBindingNavigator.MoveLastItem = Me.BindingNavigatorMoveLastItem
        Me.SampleDatatableBindingNavigator.MoveNextItem = Me.BindingNavigatorMoveNextItem
        Me.SampleDatatableBindingNavigator.MovePreviousItem = Me.BindingNavigatorMovePreviousItem
        Me.SampleDatatableBindingNavigator.Name = "SampleDatatableBindingNavigator"
        Me.SampleDatatableBindingNavigator.PositionItem = Me.BindingNavigatorPositionItem
        Me.SampleDatatableBindingNavigator.Size = New System.Drawing.Size(277, 25)
        Me.SampleDatatableBindingNavigator.TabIndex = 2
        Me.SampleDatatableBindingNavigator.Text = "BindingNavigator1"
        '
        'BindingNavigatorAddNewItem
        '
        Me.BindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorAddNewItem.Image = CType(resources.GetObject("BindingNavigatorAddNewItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorAddNewItem.Name = "BindingNavigatorAddNewItem"
        Me.BindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorAddNewItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorAddNewItem.Text = "Add new"
        '
        'BindingNavigatorCountItem
        '
        Me.BindingNavigatorCountItem.Name = "BindingNavigatorCountItem"
        Me.BindingNavigatorCountItem.Size = New System.Drawing.Size(35, 22)
        Me.BindingNavigatorCountItem.Text = "of {0}"
        Me.BindingNavigatorCountItem.ToolTipText = "Total number of items"
        '
        'BindingNavigatorDeleteItem
        '
        Me.BindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorDeleteItem.Image = CType(resources.GetObject("BindingNavigatorDeleteItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorDeleteItem.Name = "BindingNavigatorDeleteItem"
        Me.BindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorDeleteItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorDeleteItem.Text = "Delete"
        '
        'BindingNavigatorMoveFirstItem
        '
        Me.BindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorMoveFirstItem.Image = CType(resources.GetObject("BindingNavigatorMoveFirstItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorMoveFirstItem.Name = "BindingNavigatorMoveFirstItem"
        Me.BindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorMoveFirstItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorMoveFirstItem.Text = "Move first"
        '
        'BindingNavigatorMovePreviousItem
        '
        Me.BindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorMovePreviousItem.Image = CType(resources.GetObject("BindingNavigatorMovePreviousItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorMovePreviousItem.Name = "BindingNavigatorMovePreviousItem"
        Me.BindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorMovePreviousItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorMovePreviousItem.Text = "Move previous"
        '
        'BindingNavigatorSeparator
        '
        Me.BindingNavigatorSeparator.Name = "BindingNavigatorSeparator"
        Me.BindingNavigatorSeparator.Size = New System.Drawing.Size(6, 25)
        '
        'BindingNavigatorPositionItem
        '
        Me.BindingNavigatorPositionItem.AccessibleName = "Position"
        Me.BindingNavigatorPositionItem.AutoSize = False
        Me.BindingNavigatorPositionItem.Name = "BindingNavigatorPositionItem"
        Me.BindingNavigatorPositionItem.Size = New System.Drawing.Size(50, 23)
        Me.BindingNavigatorPositionItem.Text = "0"
        Me.BindingNavigatorPositionItem.ToolTipText = "Current position"
        '
        'BindingNavigatorSeparator1
        '
        Me.BindingNavigatorSeparator1.Name = "BindingNavigatorSeparator1"
        Me.BindingNavigatorSeparator1.Size = New System.Drawing.Size(6, 25)
        '
        'BindingNavigatorMoveNextItem
        '
        Me.BindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorMoveNextItem.Image = CType(resources.GetObject("BindingNavigatorMoveNextItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorMoveNextItem.Name = "BindingNavigatorMoveNextItem"
        Me.BindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorMoveNextItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorMoveNextItem.Text = "Move next"
        '
        'BindingNavigatorMoveLastItem
        '
        Me.BindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.BindingNavigatorMoveLastItem.Image = CType(resources.GetObject("BindingNavigatorMoveLastItem.Image"), System.Drawing.Image)
        Me.BindingNavigatorMoveLastItem.Name = "BindingNavigatorMoveLastItem"
        Me.BindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = True
        Me.BindingNavigatorMoveLastItem.Size = New System.Drawing.Size(23, 22)
        Me.BindingNavigatorMoveLastItem.Text = "Move last"
        '
        'BindingNavigatorSeparator2
        '
        Me.BindingNavigatorSeparator2.Name = "BindingNavigatorSeparator2"
        Me.BindingNavigatorSeparator2.Size = New System.Drawing.Size(6, 25)
        '
        'SampleDatatableBindingNavigatorSaveItem
        '
        Me.SampleDatatableBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.SampleDatatableBindingNavigatorSaveItem.Image = CType(resources.GetObject("SampleDatatableBindingNavigatorSaveItem.Image"), System.Drawing.Image)
        Me.SampleDatatableBindingNavigatorSaveItem.Name = "SampleDatatableBindingNavigatorSaveItem"
        Me.SampleDatatableBindingNavigatorSaveItem.Size = New System.Drawing.Size(23, 22)
        Me.SampleDatatableBindingNavigatorSaveItem.Text = "Save Data"
        '
        'DateTextBox
        '
        Me.DateTextBox.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.SampleDatatableBindingSource, "Date", True))
        Me.DateTextBox.Location = New System.Drawing.Point(132, 22)
        Me.DateTextBox.Name = "DateTextBox"
        Me.DateTextBox.Size = New System.Drawing.Size(135, 20)
        Me.DateTextBox.TabIndex = 4
        '
        'SpeciesTextBox
        '
        Me.SpeciesTextBox.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.SampleDatatableBindingSource, "Species", True))
        Me.SpeciesTextBox.Location = New System.Drawing.Point(66, 45)
        Me.SpeciesTextBox.Name = "SpeciesTextBox"
        Me.SpeciesTextBox.Size = New System.Drawing.Size(201, 20)
        Me.SpeciesTextBox.TabIndex = 6
        '
        'LongitudeTextBox
        '
        Me.LongitudeTextBox.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.SampleDatatableBindingSource, "Longitude", True))
        Me.LongitudeTextBox.Location = New System.Drawing.Point(75, 71)
        Me.LongitudeTextBox.Name = "LongitudeTextBox"
        Me.LongitudeTextBox.Size = New System.Drawing.Size(192, 20)
        Me.LongitudeTextBox.TabIndex = 8
        '
        'LatitudeTextBox
        '
        Me.LatitudeTextBox.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.SampleDatatableBindingSource, "Latitude", True))
        Me.LatitudeTextBox.Location = New System.Drawing.Point(66, 94)
        Me.LatitudeTextBox.Name = "LatitudeTextBox"
        Me.LatitudeTextBox.Size = New System.Drawing.Size(201, 20)
        Me.LatitudeTextBox.TabIndex = 10
        '
        'NotesTextBox
        '
        Me.NotesTextBox.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.SampleDatatableBindingSource, "Notes", True))
        Me.NotesTextBox.Location = New System.Drawing.Point(105, 120)
        Me.NotesTextBox.Multiline = True
        Me.NotesTextBox.Name = "NotesTextBox"
        Me.NotesTextBox.Size = New System.Drawing.Size(162, 80)
        Me.NotesTextBox.TabIndex = 12
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(277, 214)
        Me.Controls.Add(DateLabel)
        Me.Controls.Add(Me.DateTextBox)
        Me.Controls.Add(SpeciesLabel)
        Me.Controls.Add(Me.SpeciesTextBox)
        Me.Controls.Add(LongitudeLabel)
        Me.Controls.Add(Me.LongitudeTextBox)
        Me.Controls.Add(LatitudeLabel)
        Me.Controls.Add(Me.LatitudeTextBox)
        Me.Controls.Add(NotesLabel)
        Me.Controls.Add(Me.NotesTextBox)
        Me.Controls.Add(Me.SampleDatatableBindingNavigator)
        Me.Controls.Add(Me.Sync)
        Me.Controls.Add(Me.Clear)
        Me.Name = "Form1"
        Me.Text = "FETCH Data Tagging"
        CType(Me.SampleDatabaseDataSet, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.SampleDatatableBindingSource, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.SampleDatatableBindingNavigator, System.ComponentModel.ISupportInitialize).EndInit()
        Me.SampleDatatableBindingNavigator.ResumeLayout(False)
        Me.SampleDatatableBindingNavigator.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Clear As System.Windows.Forms.Button
    Friend WithEvents Sync As System.Windows.Forms.Button
    Friend WithEvents SampleDatabaseDataSet As FETCH_Data_Tagging.SampleDatabaseDataSet
    Friend WithEvents SampleDatatableBindingSource As System.Windows.Forms.BindingSource
    Friend WithEvents SampleDatatableTableAdapter As FETCH_Data_Tagging.SampleDatabaseDataSetTableAdapters.SampleDatatableTableAdapter
    Friend WithEvents TableAdapterManager As FETCH_Data_Tagging.SampleDatabaseDataSetTableAdapters.TableAdapterManager
    Friend WithEvents SampleDatatableBindingNavigator As System.Windows.Forms.BindingNavigator
    Friend WithEvents BindingNavigatorAddNewItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorCountItem As System.Windows.Forms.ToolStripLabel
    Friend WithEvents BindingNavigatorDeleteItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorMoveFirstItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorMovePreviousItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorSeparator As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents BindingNavigatorPositionItem As System.Windows.Forms.ToolStripTextBox
    Friend WithEvents BindingNavigatorSeparator1 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents BindingNavigatorMoveNextItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorMoveLastItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents BindingNavigatorSeparator2 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents SampleDatatableBindingNavigatorSaveItem As System.Windows.Forms.ToolStripButton
    Friend WithEvents DateTextBox As System.Windows.Forms.TextBox
    Friend WithEvents SpeciesTextBox As System.Windows.Forms.TextBox
    Friend WithEvents LongitudeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents LatitudeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents NotesTextBox As System.Windows.Forms.TextBox

End Class
