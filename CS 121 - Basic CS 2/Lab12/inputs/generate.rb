
vals = []
1.upto ARGV[0].to_i do |x|
  vals <<  Random.new.rand(0..3456789)
end

#puts vals
#puts vals.sort
puts vals.sort.reverse
