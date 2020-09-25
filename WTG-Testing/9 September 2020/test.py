
def get_KML(target,ref,name):
    
    total_coord = []
    doc, tag, text = Doc().tagtext()
    
    with tag("kml",('xmlns',"http://www.opengis.net/kml/2.2")):
        with tag("Document",('xmlns',"")):
            with tag("name"):
                text('C2')

            with tag('open'):
                text("1")

            with tag("ExtendedData",('xmlns:mis','www.dji.com')):
                with tag('mis:type'):
                    text('Waypoint')
                with tag('mis:stationType'):     # CHECK THIS SETTING AND WHAT IT IS 
                    text('0')

            with tag('Style',('id','waypointStyle')):
                with tag('IconStyle'):
                    with tag('Icon'):
                        with tag('href'):
                            text('https://cdnen.dji-flighthub.com/static/app/images/point.png')
            with tag('Folder'):
                trig = 1
                for pathar in target: 

                    if trig == 1 :
                        trig= trig*-1
                        ref_new = ref
                        pathar = pathar[::-1]
                        ref_new = ref[::-1]
                    elif trig == -1:
                        trig= trig*-1
                        ref_new = ref 


                    for i in range(len(pathar)):
                        d,b = haversine(  pathar[i][1],pathar[i][0],ref_new[i][1],ref_new[i][0]  )
                        la = pathar[i][0]
                        lo = pathar[i][1]
                        a = pathar[i][2]
                        total_coord.append([lo,la,a])
                        
                        with tag('Placemark'):
                            with tag('name'):
                                text(f'Waypoint{i+1}')
                            with tag('visibility'):
                                text(f'1')
                            with tag('description'):
                                text(f'Waypoint')
                            with tag('styleUrl'):
                                text(f'#waypointStyle')

                            with tag('ExtendedData',('xmlns:mis', "www.dji.com")):
                                with tag('mis:useWaylineAltitude'):
                                    text('false')

                                with tag('mis:heading'):
                                    text(f'{b}')

                                with tag('mis:turnMode'):
                                    text('Auto')

                                with tag('mis:gimbalPitch'):
                                    text('0.0')

                                with tag('mis:useWaylineSpeed'):
                                    text('false')

                                with tag('mis:speed'):
                                    text('1.0')

                                with tag('mis:useWaylineHeadingMode'):
                                    text('true')

                                with tag('mis:useWaylinePointType'):
                                    text('true')

                                with tag('mis:pointType'):
                                    text('LineStop')

                                with tag('mis:cornerRadius'):
                                    text('0.2')

                                with tag('mis:actions',('param', "10000"),('accuracy', "0"),('cameraIndex', "0"),('payloadType', "0")
                                            ,('payloadIndex', "0")):
                                    text('Hover')

                            with tag("Point"):
                                with tag('altitudeMode'):
                                        text('relativeToGround')

                                with tag('coordinates'):
                                        text(f'{lo},{la},{a}')

            with tag('Placemark'):
                with tag('name'):
                    text(f'Wayline')

                with tag('description'):
                    text(f'Wayline')

                with tag('visibility'):
                    text(f'1')

                with tag('ExtendedData',('xmlns:mis', "www.dji.com")):

                    with tag('mis:altitude'):
                        text('20.0')

                    with tag('mis:autoFlightSpeed'):
                        text(f'1.0')

                    with tag('mis:actionOnFinish'):
                        text('Hover')

                    with tag('mis:headingMode'):
                        text('UsePointSetting')

                    with tag('mis:gimbalPitchMode'):
                        text('UsePointSetting')

                    with tag('mis:powerSaveMode'):
                        text('false')

                    with tag('mis:waypointType'):
                        text('LineStop')

                    with tag('mis:droneInfo'):
                        with tag('mis:droneType'):
                            text('COMMON')
                        with tag('mis:advanceSettings'):
                            text('false')
                        with tag('mis:droneCameras'):
                            text('')
                        with tag('mis:droneHeight'):
                            with tag('mis:useAbsolute'):
                                text('false')
                            with tag('mis:hasTakeoffHeight'):
                                text('false')
                            with tag('mis:takeoffHeight'):
                                text('0.0')


                with tag('styleUrl'):
                    text('#waylineGreenPoly')

                with tag("LineString"):
                    with tag('tessellate'):
                            text('1')

                    with tag('altitudeMode'):
                            text('relativeToGround')

                    with tag('coordinates'):
                        coordinates_total = ''

                        for i in total_coord:
                            coordinates_total = coordinates_total + str(i[0]) + ',' + str(i[1]) + ',' + str(i[2])[:5] + ' '

                        text(f'{coordinates_total}')


    result = indent(
        doc.getvalue(),
        indentation = ' '*4,
        newline = '\r\n'
    )

    

    save_path_file = name
    with open(save_path_file, "w") as f: 
        f.write(result)  


