import plissken

print '##############################'
print 'plissken.escape_html'

print '&: ',plissken.escape_html('&')
print '>: ',plissken.escape_html('>')
print '<: ',plissken.escape_html('<')
print '": ',plissken.escape_html('"')
print '\': ',plissken.escape_html('\'')
print '/: ',plissken.escape_html('/')

print '##############################'
print 'plissken.unescape_html'

print '&amp;:  ',plissken.unescape_html('&amp;')
print '&gt;:   ',plissken.unescape_html('&gt;')
print '&lt;:   ',plissken.unescape_html('&lt;')
print '&quot;: ',plissken.unescape_html('&quot;')
print '&#39;:  ',plissken.unescape_html('&#39;')
print '&#47;:  ',plissken.unescape_html('&#47;')

print '##############################'
print 'plissken.escape_js'

print '": ',plissken.escape_js('"')
print '\': ',plissken.escape_js('\'')

print '##############################'
print 'plissken.unescape_js'

print '\\": ',plissken.unescape_js('\\"')
print '\\\': ',plissken.unescape_js('\\\'')

print '##############################'